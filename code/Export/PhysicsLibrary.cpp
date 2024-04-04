#include "PhysicsLibrary.h"

Body* CreateSphereBody(float invMass, float elasticity, float friction, float radius) {
	Body* body = new Body(invMass, elasticity, friction);
	ShapeSphere* sphere = new ShapeSphere(radius);
	body->m_shape = sphere;
	return body;
}

Vec3* GetBodyPosition(Body* body) {
	return &body->m_position;
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

float GetX(Vec3* vector) {
	return vector->x;
}

float GetY(Vec3* vector) {
	return vector->y;
}

float GetZ(Vec3* vector) {
	return vector->z;
}
