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

	bodyA->m_linearVelocity.Zero();
	bodyB->m_linearVelocity.Zero();

	// Let's also move our colliding objects to just outside of each other.
	// This is called "Projection Method"
	const float tA = bodyA->m_invMass / (bodyA->m_invMass + bodyB->m_invMass);
	const float tB = bodyB->m_invMass / (bodyA->m_invMass + bodyB->m_invMass);

	const Vec3 ds = contact.ptOnB_WorldSpace - contact.ptOnA_WorldSpace;
	bodyA->m_position += ds * tA;
	bodyB->m_position -= ds * tB;
}