#include <allegro5/allegro.h>
#include "Core/Game/Game.h"
#include "Core/GameState/GameState.h"
#include "Core/GameState/GameStateManager.h"
#include "Core/ECS/EntityFu.h"
#include "Game/GameState/TestState.h"
#include "Game/Component/ComDefine.h"

/*Cid Entity::Component::numCids = 0;*/

int main()
{
	GameStateManager::getInstance()->push(new TestState());

	Game::getInstance()->run();

	return 0;
}