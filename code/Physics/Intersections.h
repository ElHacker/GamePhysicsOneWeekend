//
//	Intersections.h
//
#pragma once
#include "Contact.h"

#ifdef PHYSICSLIBRARY_EXPORTS
#define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#define PHYSICSLIBRARY_API __declspec(dllimport)
#endif

bool Intersect( Body * bodyA, Body * bodyB, contact_t & contact );
extern "C" PHYSICSLIBRARY_API bool Intersect(Body * bodyA, Body * bodyB, const float dt, contact_t & contact);