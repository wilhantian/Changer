#ifndef _PHYSICS_SYSTEM_H_
#define _PHYSICS_SYSTEM_H_

#include "Core/ECS/EntityFu.h"

class PhysicsSystem : public System
{
public:
	static void tick(double fixedDelta);
};

#endif