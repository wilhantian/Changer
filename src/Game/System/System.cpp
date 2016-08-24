#include "System.h"
#include <allegro5/allegro.h>

void RenderSystem::tick(double fixedDelta)
{
	std::vector<Eid> all = Entity::getAll<SkinComp>();
	
	for (Eid id : all)
	{
		Ent e(id);
		
		if (!e.skin.bitmap)
		{
			e.skin.bitmap = al_load_bitmap(e.skin.name);
		}

		al_draw_bitmap(e.skin.bitmap, e.position.x, e.position.y, 0);
	}
}

