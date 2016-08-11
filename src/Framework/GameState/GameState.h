#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

#include "Framework/Base/BaseObject.h"

class GameState : public BaseObject
{
public:
	GameState();
	virtual ~GameState();

	CREATE_FUNC(GameState);
	virtual bool init();
public:
	virtual void onEnter();
	virtual void onExit();
	virtual void update(float dt);
	virtual void draw();
	virtual void handleEvent();
};

#endif