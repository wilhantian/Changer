#include "GameStateManager.h"
#include "GameState.h"

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
	if (!gameState || _curGameState == gameState)
		return;

	if (_curGameState)
		_curGameState->onExit();
	
	_curGameState = gameState;
	
	if (_curGameState)
		_curGameState->onEnter();
}

void GameStateManager::push(GameState* gameState)
{

}

void GameStateManager::pop()
{

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

GameStateManager* GameStateManager::_instance = nullptr;

