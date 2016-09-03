#ifndef _PHYSICS_SYSTEM_H_
#define _PHYSICS_SYSTEM_H_

#include "Core/ECS/EntityFu.h"

class b2World;

class PhysicsSystem : public System
{
public:
	static void tick(double fixedDelta);

private:
	static b2World* _world;
};

#endif//_PHYSICS_SYSTEM_H_