#include "RenderSystem.h"
#include <allegro5/allegro.h>
#include "Game/Component/ComDefine.h"

void RenderSystem::tick(double fixedDelta)
{
	auto all = Entity::getAll<RenderCom>();
	for (Eid id : all)
	{
		Ent e(id);
		MoveCom& move = e.move;
		RenderCom& render = e.render;
		
		IF_COM_NULL_CONTINUE(move);
		IF_COM_NULL_CONTINUE(render);

		if ((render.curDelay += fixedDelta) >= 1.0f / render.frameRate)
		{
			render.curDelay = 0;
			render.curIndex = (render.curIndex + 1) % render.frames.size();
		}

		al_draw_bitmap(render.frames[render.curIndex], move.position.x, move.position.y, 0);
	}
}

