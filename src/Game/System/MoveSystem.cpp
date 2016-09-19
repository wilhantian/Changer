#include "MoveSystem.h"
#include "Game/Component/ComDefine.h"

void MoveSystem::tick(double fixedDelta)
{
	auto all = Entity::getAll<MoveCom>();
	for (Eid id : all)
	{
		Ent e(id);
		MoveCom& move = e.move;

		float x = 0;
		float y = 0;

		switch (move.direction)
		{
		case kDirection::Up :
			x = 0;
			y = -1 * move.speed;
			break;
		case kDirection::RightUp :
			x = 1 * move.tiltSpeed;
			y = -1 * move.tiltSpeed;
			break;
		case kDirection::Right :
			x = 1 * move.speed;
			y = 0;
			break;
		case kDirection::RightDown :
			x = 1 * move.tiltSpeed;
			y = 1 * move.tiltSpeed;
			break;
		case kDirection::Down :
			x = 0;
			y = 1 * move.speed;
			break;
		case kDirection::LeftDown :
			x = -1 * move.tiltSpeed;
			y = 1 * move.tiltSpeed;
			break;
		case kDirection::Left :
			x = -1 * move.speed;
			y = 0;
			break;
		case kDirection::LeftUp :
			x = -1 * move.tiltSpeed;
			y = -1 * move.tiltSpeed;
			break;
		}

		x *= fixedDelta;
		y *= fixedDelta;

		move.position.x += x;
		move.position.y += y;
	}
}

