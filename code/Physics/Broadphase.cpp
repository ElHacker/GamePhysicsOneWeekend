//
//  Broadphase.cpp
//
#include "Broadphase.h"

struct pseudoBody_t {
	int id;
	float value;
	bool ismin;
};

int CompareSAP(const void* a, const void* b) {
	const pseudoBody_t* ea = (const pseudoBody_t*)a;
	const pseudoBody_t* eb = (const pseudoBody_t*)b;

	if (ea->value < eb->value) {
		return -1;
	}
	return 1;
}

void SortBodiesBounds(const Body* bodies, const int num, pseudoBody_t* sortedArray, const float dt_sec) {
	Vec3 axis = Vec3(1, 1, 1);
	axis.Normalize();

	for (int i = 0; i < num; ++i) {
		const Body& body = bodies[i];
		Bounds bounds = body.m_shape->GetBounds(body.m_position, body.m_orientation);

		// Expand the bounds by the linear velocity
		bounds.Expand(bounds.mins + body.m_linearVelocity * dt_sec);
		bounds.Expand(bounds.maxs + body.m_linearVelocity * dt_sec);

		const float epsilon = 0.01f;
		bounds.Expand(bounds.mins + Vec3(-1, -1, -1) * epsilon);
		bounds.Expand(bounds.maxs + Vec3(1, 1, 1) * epsilon);

		sortedArray[i * 2 + 0].id = i;
		sortedArray[i * 2 + 0].value = axis.Dot(bounds.mins);
		sortedArray[i * 2 + 0].ismin = true;

		sortedArray[i * 2 + 1].id = i;
		sortedArray[i * 2 + 1].value = axis.Dot(bounds.maxs);
		sortedArray[i * 2 + 1].ismin = false;
	}
	qsort(sortedArray, num * 2, sizeof(pseudoBody_t), CompareSAP);
}

void BuildPairs(std::vector<collisionPair_t>& collisionPairs, const pseudoBody_t* sortedBodies, const int num) {
	collisionPairs.clear();

	// Now that the bodies are sorted, build the collision pairs.
	for (int i = 0; i < num * 2; ++i) {
		const pseudoBody_t& a = sortedBodies[i];
		if (!a.ismin) {
			continue;
		}

		collisionPair_t pair;
		pair.a = a.id;

		for (int j = i + 1; j < num * 2; ++j) {
			const pseudoBody_t& b = sortedBodies[j];
			// If we've hit the end of the element, then we're done creating pairs with a
			if (b.id == a.id) {
				break;
			}

			if (!b.ismin) {
				continue;
			}

			pair.b = b.id;
			collisionPairs.push_back(pair);
		}
	}
}

void SweepAndPrune1D(const Body* bodies, const int num, std::vector<collisionPair_t>& finalPairs, const float dt_sec) {
	pseudoBody_t* sortedBodies = (pseudoBody_t*)alloca(sizeof(pseudoBody_t) * num * 2);
	SortBodiesBounds(bodies, num, sortedBodies, dt_sec);
	BuildPairs(finalPairs, sortedBodies, num);
}

/*
====================================================
BroadPhase
====================================================
*/
void BroadPhase( const Body * bodies, const int num, std::vector< collisionPair_t > & finalPairs, const float dt_sec ) {
	finalPairs.clear();
	SweepAndPrune1D(bodies, num, finalPairs, dt_sec);
}