#include "RenderSystem.h"

#include "Game/Component/ComDefine.h"

void RenderSystem::tick(double fixedDelta)
{
	auto all = Entity::getAll<SpriteCom>();
	for (Eid id : all)
	{
		Ent e(id);
		PositionCom& position = e.position;
		SpriteCom& sprite = e.sprite;
		
		IF_COM_NULL_CONTINUE(position);
		IF_COM_NULL_CONTINUE(sprite);

		if ((sprite.delay += fixedDelta) >= 1.f/sprite.rate)
		{
			sprite.index = (sprite.index + 1) % sprite.size;
			sprite.curFrame = sprite.frames[sprite.index];
			sprite.delay = 0;
		}

		al_draw_bitmap(sprite.curFrame, position.x, position.y, 0);
	}
}

