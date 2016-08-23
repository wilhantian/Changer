#include <allegro5/allegro.h>
#include "Framework/Game/Game.h"
#include "Framework/ECS/EntityFu.h"

Cid Entity::Component::numCids = 0;

int main()
{
	Game::getInstance()->run();

	return 0;
}