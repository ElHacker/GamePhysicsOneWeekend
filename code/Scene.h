//
//  Scene.h
//
#pragma once
#include <vector>

#include "Physics/Shapes.h"
#include "Physics/Body.h"
#include "Physics/Constraints.h"
#include "Physics/Manifold.h"

#ifdef PHYSICSLIBRARY_EXPORTS
#define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#define PHYSICSLIBRARY_API __declspec(dllimport)
#endif

/*
====================================================
Scene
====================================================
*/
class PHYSICSLIBRARY_API Scene {
public:
	Scene() { m_bodies.reserve( 128 ); }
	~Scene();

	void Reset();
	void Initialize();
	void Update( const float dt_sec );	

	std::vector< Body > m_bodies;
	std::vector< Constraint * >	m_constraints;
	ManifoldCollector m_manifolds;
};

