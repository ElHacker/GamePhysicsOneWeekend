#pragma once

#include "../Scene.h"
#include "../Physics/Body.h"
#include "../Physics/Shapes.h"
#include "../Math/Vector.h"

#ifdef PHYSICSLIBRARY_EXPORTS
#define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#define PHYSICSLIBRARY_API __declspec(dllimport)
#endif

extern "C" PHYSICSLIBRARY_API Scene *  CreateScene();

// TODO(elhacker): Here I return a Body pointer to allow the client to get the correct reference to the Body instance being
// used in the Update simulation. I think it would be better to use a Callback mechanism to allow Scene::Update to automatically
// update the simulation on the client.
extern "C" PHYSICSLIBRARY_API Body* AddBodyToScene(Scene* scene, Body* body);

extern "C" PHYSICSLIBRARY_API void UpdateScene(Scene* scene, const float dt_sec);

extern "C" PHYSICSLIBRARY_API Body * CreateSphereBody(float invMass, float elasticity, float friction, float radius);

extern "C" PHYSICSLIBRARY_API Vec3 * GetBodyPosition(Body* body);

extern "C" PHYSICSLIBRARY_API Quat * GetBodyOrientation(Body* body);

extern "C" PHYSICSLIBRARY_API void SetBodyPosition(Body* body, float x, float y, float z);

extern "C" PHYSICSLIBRARY_API void SetBodyOrientation(Body* body, float x, float y, float z, float w);

extern "C" PHYSICSLIBRARY_API void SetBodyLinearVelocity(Body* body, float x, float y, float z);

extern "C" PHYSICSLIBRARY_API void SetBodyAngularVelocity(Body* body, float x, float y, float z);

extern "C" PHYSICSLIBRARY_API float GetVectorX(Vec3* vector);

extern "C" PHYSICSLIBRARY_API float GetVectorY(Vec3* vector);

extern "C" PHYSICSLIBRARY_API float GetVectorZ(Vec3* vector);

extern "C" PHYSICSLIBRARY_API float GetQuatX(Quat* quat);

extern "C" PHYSICSLIBRARY_API float GetQuatY(Quat* quat);

extern "C" PHYSICSLIBRARY_API float GetQuatZ(Quat* quat);

extern "C" PHYSICSLIBRARY_API float GetQuatW(Quat* quat);

