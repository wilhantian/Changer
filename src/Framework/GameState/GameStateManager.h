#ifndef _GAME_STATE_MANAGER_H_
#define _GAME_STATE_MANAGER_H_

class GameState;

class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();

public:
	void switchTo(GameState* gameState);
	void push(GameState* gameState);
	void pop();

protected:
	GameState* _curGameState;
};

#endif