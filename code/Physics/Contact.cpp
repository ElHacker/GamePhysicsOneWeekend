//
//  Contact.cpp
//
#include "Contact.h"

/*
====================================================
ResolveContact
====================================================
*/
void ResolveContact( contact_t & contact ) {
	Body* bodyA = contact.bodyA;
	Body* bodyB = contact.bodyB;

	const Vec3 ptOnA = contact.ptOnA_WorldSpace;
	const Vec3 ptOnB = contact.ptOnB_WorldSpace;

	const float elasticityA = bodyA->m_elasticity;
	const float elasticityB = bodyB->m_elasticity;
	const float elasticity = elasticityA * elasticityB;

	const float invMassA = bodyA->m_invMass;
	const float invMassB = bodyB->m_invMass;

	const Mat3 invWorldInertiaA = bodyA->GetInverseInertiaTensorWorldSpace();
	const Mat3 invWorldInertiaB = bodyB->GetInverseInertiaTensorWorldSpace();

	const Vec3 n = contact.normal;

	const Vec3 ra = ptOnA - bodyA->GetCenterOfMassWorldSpace();
	const Vec3 rb = ptOnB - bodyB->GetCenterOfMassWorldSpace();

	const Vec3 angularJA = (invWorldInertiaA * ra.Cross(n)).Cross(ra);
	const Vec3 angularJB = (invWorldInertiaB * rb.Cross(n)).Cross(rb);
	const float angularFactor = (angularJA + angularJB).Dot(n);

	// Get the world space velocity of the motion and rotation
	const Vec3 velA = bodyA->m_linearVelocity + bodyA->m_angularVelocity.Cross(ra);
	const Vec3 velB = bodyB->m_linearVelocity + bodyB->m_angularVelocity.Cross(rb);

	// Calculate the collision impulse
	const Vec3 vab = velA - velB;
	const float ImpulseJ = (1.0f + elasticity) * vab.Dot(n) / (invMassA + invMassB + angularFactor);
	const Vec3 vectorImpulseJ = n * ImpulseJ;

	bodyA->ApplyImpulse(ptOnA, vectorImpulseJ * -1.0f);
	bodyB->ApplyImpulse(ptOnB, vectorImpulseJ * 1.0f);

	// Let's also move our colliding objects to just outside of each other.
	// This is called "Projection Method"
	const float tA = bodyA->m_invMass / (bodyA->m_invMass + bodyB->m_invMass);
	const float tB = bodyB->m_invMass / (bodyA->m_invMass + bodyB->m_invMass);

	const Vec3 ds = contact.ptOnB_WorldSpace - contact.ptOnA_WorldSpace;
	bodyA->m_position += ds * tA;
	bodyB->m_position -= ds * tB;
}