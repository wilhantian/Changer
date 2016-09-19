#ifndef _MOVE_SYSTEM_H_
#define _MOVE_SYSTEM_H_

#include "Core/ECS/EntityFu.h"

class MoveSystem : public System
{
public:
	static void tick(double fixedDelta);
};

#endif