#include "Game.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "Core/Logger/Logger.h"
#include "Core/GameState/GameState.h"
#include "Core/GameState/GameStateManager.h"

Game::Game():
_isRunning(true),
_gameDelay(1.0/60.0),
_curDelay(0),
_nowTime(0),
_lastUpdateTime(0)
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

bool Game::init()
{
    if (!al_init() || !al_init_image_addon() || !al_init_primitives_addon())
    {
        Logger::error("al init error");
        return false;
    }
    
    if(!(_display = al_create_display(800, 600)))
    {
        Logger::error("al create display error");
        return false;
    }
    
    return true;
}

void Game::run()
{
//	if (!al_init() || !al_init_image_addon() || !al_init_primitives_addon())
//    {
//        Logger::error("al init error");
//        return;
//    }
//
//    if(!(_display = al_create_display(800, 600)))
//    {
//        Logger::error("al create display error");
//        return;
//    }
    
	while (_isRunning)
	{	
		if (_isNeedUpdate())
		{
			GameStateManager::getInstance()->handleEvent();
			al_clear_to_color(al_map_rgb_f(0, 0, 0));
			GameStateManager::getInstance()->update(_curDelay);
			GameStateManager::getInstance()->draw();
            al_flip_display();
		}
	}

	al_destroy_display(_display);
}

void Game::stop()
{
	_isRunning = false;
}

bool Game::_isNeedUpdate()
{
	_nowTime = al_get_time();
	_curDelay = _nowTime - _lastUpdateTime;
	if (_curDelay >= _gameDelay)
	{
		_lastUpdateTime = _nowTime;
		return true;
	}
	else
	{
		al_rest(0);
		return false;
	}
	
}

Game* Game::_instance = nullptr;
