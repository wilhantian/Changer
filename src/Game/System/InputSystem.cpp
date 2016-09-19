#include "InputSystem.h"

#include "Game/Component/ComDefine.h"

void InputSystem::tick(double fixedDelta)
{
	auto all = Entity::getAll<MoveCom>();
	for (Eid id : all)
	{
		Ent e(id);
		MoveCom& move = e.move;
		
		ALLEGRO_KEYBOARD_STATE keyState;
		al_get_keyboard_state(&keyState);
		
		if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
		{
			move.speed = 120;
			move.direction = kDirection::Left;
		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
		{
			move.speed = 120;
			move.direction = kDirection::Right;
		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_UP))
		{
			move.speed = 120;
			move.direction = kDirection::Up;
		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_DOWN))
		{
			move.speed = 120;
			move.direction = kDirection::Down;
		}
		else
		{
			move.speed = 0;
			move.direction = kDirection::Down;
		}
	}
}

