#include "GameStateManager.h"
#include "GameState.h"
#include "Framework/Base/Logger.h"

GameStateManager::GameStateManager():
_curGameState(nullptr)
{
	
}

GameStateManager::~GameStateManager()
{
	
}

GameStateManager* GameStateManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new GameStateManager();
	}
	return _instance;
}

void GameStateManager::destory()
{
	if (_instance)
	{
		delete _instance;
	}
}

void GameStateManager::switchTo(GameState* gameState)
{
    pop();
    push(gameState);
}

void GameStateManager::push(GameState* gameState)
{
    if(!gameState)
    {
        Logger::error("push game state error, the state is null");
        return;
    }
    
    if (_stateList.size() > 0)
    {
        GameState* lastState = _stateList.back();
        
        if (lastState)
        {
            lastState->onExit();
        }
    }
    
    _curGameState = gameState;
    gameState->retain();
    gameState->onEnter();
    _stateList.push_back(gameState);
}

void GameStateManager::pop()
{
    if (_stateList.size() == 0) {
        return;
    }
    
    GameState* state = _stateList.back();
    if (state)
    {
        state->onExit();
        state->release();
    }
    
    _stateList.pop_back();
    
    state = _stateList.back();
    
    if(state)
    {
        _curGameState = state;
        state->onEnter();
    }
    else
    {
        _curGameState = nullptr;
    }
    
}

void GameStateManager::update(float dt)
{
	if (_curGameState)
	{
		_curGameState->update(dt);
	}
}

void GameStateManager::draw()
{
	if (_curGameState)
	{
		_curGameState->draw();
	}
}

void GameStateManager::handleEvent()
{
	if (_curGameState)
	{
		_curGameState->handleEvent();
	}
}

GameState* GameStateManager::getCurGameState()
{
    return _curGameState;
}

GameStateManager* GameStateManager::_instance = nullptr;

