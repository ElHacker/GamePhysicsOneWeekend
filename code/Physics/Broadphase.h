//
//	Broadphase.h
//
#pragma once
#include "Body.h"
#include <vector>

#ifdef PHYSICSLIBRARY_EXPORTS
#define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#define PHYSICSLIBRARY_API __declspec(dllimport)
#endif


struct collisionPair_t {
	int a;
	int b;

	bool operator == ( const collisionPair_t & rhs ) const {
		return ( ( ( a == rhs.a ) && ( b == rhs.b ) ) || ( ( a == rhs.b ) && ( b == rhs.a ) ) );
	}
	bool operator != ( const collisionPair_t & rhs ) const {
		return !( *this == rhs );
	}
};

extern "C" PHYSICSLIBRARY_API void BroadPhase(const Body * bodies, const int num, std::vector< collisionPair_t > &finalPairs, const float dt_sec);