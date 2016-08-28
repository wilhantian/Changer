#ifndef _SPRITE_SYSTEM_H_
#define _SPRITE_SYSTEM_H_

#include "Core/ECS/EntityFu.h"

class SpriteSystem : public System
{
public:
	static void tick(double fixedDelta);
};

#endif//_SPRITE_SYSTEM_H_