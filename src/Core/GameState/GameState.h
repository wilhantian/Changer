#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

/**
 * сно╥в╢л╛
 */
class GameState
{
public:
	GameState();
	virtual ~GameState();
    
public:
	virtual void onEnter();
	virtual void onExit();
	virtual void update(float dt);
	virtual void draw();
	virtual void handleEvent();
};

#endif