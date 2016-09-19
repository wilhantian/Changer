#ifndef _INPUT_SYSTEM_H_
#define _INPUT_SYSTEM_H_

#include "Core/ECS/EntityFu.h"

class InputSystem : public System
{
public:
	static void tick(double fixedDelta);
};

#endif