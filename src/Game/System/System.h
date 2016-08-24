#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "Core/ECS/EntityFu.h"
#include "Game/Component/PositionComp.h"

class RenderSystem : public System
{
public:
	static void tick(double fixedDelta);
};

#endif