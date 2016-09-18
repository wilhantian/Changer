#include "Game.h"

#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include "Core/Logger/Logger.h"
#include "Core/GameState/GameState.h"
#include "Core/GameState/GameStateManager.h"

#include "Box2D/Box2dRender.h"

Game::Game():
_isRunning(true),
_gameDelay(1.0/60.0),
_curDelay(0),
_nowTime(0),
_lastUpdateTime(0),
_eventQueue(nullptr)
{

}

Game::~Game()
{
	delete _world;
	_world = nullptr;
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
    if (!al_init() || !al_init_image_addon() || !al_init_primitives_addon() || !al_install_keyboard())
    {
        Logger::error("al init error");
        return false;
    }
    
    if(!(_display = al_create_display(800, 600)))
    {
        Logger::error("al create display error");
        return false;
    }

	_world = new b2World(b2Vec2(0, 0));
	Box2dRender* debugDraw = new Box2dRender();
	uint32 flags = 0;
	flags += b2Draw::e_shapeBit;
	flags += b2Draw::e_jointBit;  
	//flags += b2Draw::e_aabbBit;  
	//flags += b2Draw::e_pairBit;  
	//flags += b2Draw::e_centerOfMassBit;  
	debugDraw->SetFlags(flags);
	_world->SetDebugDraw(debugDraw);
    
    // events queue
    _initEventQueue();
    
    return true;
}

void Game::run()
{   
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

bool Game::_initEventQueue()
{
    _eventQueue = al_create_event_queue();
    
    if(!_eventQueue)
    {
        return false;
    }
    
    al_register_event_source(_eventQueue, al_get_display_event_source(_display));
    
    return true;
}

b2World* Game::getWorld()
{
	return _world;
}

Game* Game::_instance = nullptr;
