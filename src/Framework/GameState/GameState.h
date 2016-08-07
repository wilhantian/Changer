#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

typedef unsigned int GameStateID;

class GameState
{
public:
	GameState();
	virtual ~GameState();

public:
	virtual GameStateID getGameStateID() = 0;

	virtual void onEnter();
	virtual void onExit();
	virtual void update(float dt);
	virtual void draw();
};

#endif