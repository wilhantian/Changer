#ifndef _RENDER_SYSTEM_H_
#define _RENDER_SYSTEM_H_

#include "Core/ECS/EntityFu.h"

class RenderSystem : public System
{
public:
	static void tick(double fixedDelta);
};

#endif