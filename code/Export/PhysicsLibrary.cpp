#include "PhysicsLibrary.h"

Scene* CreateScene() {
	return new Scene;
}

Body* AddBodyToScene(Scene* scene, Body* body) {
	scene->m_bodies.push_back(*body);
	return &scene->m_bodies.back();
}

void UpdateScene(Scene* scene, const float dt_sec) {
	scene->Update(dt_sec);
}

Body* CreateSphereBody(float invMass, float elasticity, float friction, float radius) {
	Body* body = new Body(invMass, elasticity, friction);
	ShapeSphere* sphere = new ShapeSphere(radius);
	body->m_shape = sphere;
	return body;
}

Vec3* GetBodyPosition(Body* body) {
	return &body->m_position;
}

Quat* GetBodyOrientation(Body* body) {
	return &body->m_orientation;
}

void SetBodyPosition(Body* body, float x, float y, float z)
{
	body->m_position = Vec3(x, y, z);
}

void SetBodyOrientation(Body* body, float x, float y, float z, float w)
{
	body->m_orientation = Quat(x, y, z, w);
}

void SetBodyLinearVelocity(Body* body, float x, float y, float z)
{
	body->m_linearVelocity = Vec3(x, y, z);
}

void SetBodyAngularVelocity(Body* body, float x, float y, float z)
{
	body->m_angularVelocity = Vec3(x, y, z);
}

float GetVectorX(Vec3* vector) {
	return vector->x;
}

float GetVectorY(Vec3* vector) {
	return vector->y;
}

float GetVectorZ(Vec3* vector) {
	return vector->z;
}

float GetQuatX(Quat* quat) {
	return quat->x;
}

float GetQuatY(Quat* quat) {
	return quat->y;
}

float GetQuatZ(Quat* quat) {
	return quat->z;
}

float GetQuatW(Quat* quat) {
	return quat->w;
}
