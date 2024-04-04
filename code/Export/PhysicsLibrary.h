#pragma once

#include "../Physics/Body.h"
#include "../Physics/Shapes.h"
#include "../Math/Vector.h"

#ifdef PHYSICSLIBRARY_EXPORTS
#define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#define PHYSICSLIBRARY_API __declspec(dllimport)
#endif

extern "C" PHYSICSLIBRARY_API Body * CreateSphereBody(float invMass, float elasticity, float friction, float radius);

extern "C" PHYSICSLIBRARY_API Vec3 * GetBodyPosition(Body* body);

extern "C" PHYSICSLIBRARY_API void SetBodyPosition(Body* body, float x, float y, float z);

extern "C" PHYSICSLIBRARY_API void SetBodyOrientation(Body* body, float x, float y, float z, float w);

extern "C" PHYSICSLIBRARY_API void SetBodyLinearVelocity(Body* body, float x, float y, float z);

extern "C" PHYSICSLIBRARY_API void SetBodyAngularVelocity(Body* body, float x, float y, float z);

extern "C" PHYSICSLIBRARY_API float GetX(Vec3* vector);

extern "C" PHYSICSLIBRARY_API float GetY(Vec3* vector);

extern "C" PHYSICSLIBRARY_API float GetZ(Vec3* vector);
