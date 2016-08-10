#ifndef _GAME_STATE_MANAGER_H_
#define _GAME_STATE_MANAGER_H_

#include <vector>

class GameState;

class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();
	static GameStateManager* getInstance();
	static void destory();
public:
	void switchTo(GameState* gameState);
	void push(GameState* gameState);
	void pop();

	void update(float dt);
	void draw();
	void handleEvent();
protected:
	static GameStateManager* _instance;
	GameState* _curGameState;
	std::vector<GameState*> _stateList;
};

#endif