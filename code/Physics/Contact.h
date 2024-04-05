//
//	Contact.h
//
#pragma once
#include "Body.h"

#ifdef PHYSICSLIBRARY_EXPORTS
#define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#define PHYSICSLIBRARY_API __declspec(dllimport)
#endif


struct contact_t {
	Vec3 ptOnA_WorldSpace;
	Vec3 ptOnB_WorldSpace;
	Vec3 ptOnA_LocalSpace;
	Vec3 ptOnB_LocalSpace;

	Vec3 normal;	// In World Space coordinates
	float separationDistance;	// positive when non-penetrating, negative when penetrating
	float timeOfImpact;

	Body * bodyA;
	Body * bodyB;
};

extern "C" PHYSICSLIBRARY_API void ResolveContact(contact_t & contact);