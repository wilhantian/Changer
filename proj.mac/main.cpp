#include <allegro5/allegro.h>
#include "Core/GameState/GameStateManager.h"
#include "Game/GameState/TestState.h"
#include "Core/Game/Game.h"

int main(int argc, char **argv)
{
    GameStateManager::getInstance()->push(new TestState());
    Game::getInstance()->run();
    
    return 0;
}
