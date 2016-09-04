#ifndef _PHYSICS_SYSTEM_H_
#define _PHYSICS_SYSTEM_H_

#include "Core/ECS/EntityFu.h"

class b2World;

class PhysicsSystem : public System
{
public:
	static void tick(double fixedDelta);

public:
	static b2World* world;
};

#endif//_PHYSICS_SYSTEM_H_