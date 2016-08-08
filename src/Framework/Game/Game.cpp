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

void Game::destoryInstance()
{
    if(_instance)
        delete _instance;
}

void Game::run()
{

}

void Game::stop()
{
    
}

Game* Game::_instance = nullptr;
