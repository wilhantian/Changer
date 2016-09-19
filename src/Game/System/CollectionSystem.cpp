#include "CollectionSystem.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "Game/common.h"
#include "Game/Component/ComDefine.h"

void CollectionSystem::tick(double fixedDelta)
{
	auto all = Entity::getAll<CollectionCom>();
	for (Eid id : all)
	{
		Ent e(id);
		MoveCom& move = e.move;
		CollectionCom& collection = e.collection;

		IF_COM_NULL_CONTINUE(move);

		float x1 = move.position.x + collection.offset.x;
		float y1 = move.position.y + collection.offset.y;
		float x2 = x1 + collection.size.width;
		float y2 = y1 + collection.size.height;

		al_draw_rectangle(
			x1, y1,
			x2, y2,
			al_map_rgba_f(1, 0, 0, 0.5), 2);
	}
}

