#include "SpriteSystem.h"
#include "Game/Component/ComDefine.h"

void SpriteSystem::tick(double fixedDelta)
{
	auto all = Entity::getAll<SpriteCom>();
}