#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

Game* Game::getInstance()
{
	if (!_instance)
	{
		_instance = new Game();
	}
	return _instance;
}

void Game::run()
{

}

Game* Game::_instance = nullptr;
