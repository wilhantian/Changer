#ifndef _GAME_H_
#define _GAME_H_

#include "Box2D/Box2D.h"

struct ALLEGRO_DISPLAY;

class Game
{
public:
	Game();
	~Game();
	static Game* getInstance();
    static void destoryInstance();
    
public:
    bool init();
	void run();
    void stop();
    
	b2World* getWorld();

protected:
	bool _isNeedUpdate();

protected:
	static Game* _instance;
	float _nowTime;
	float _gameDelay;
	float _curDelay;
	float _lastUpdateTime;
	bool  _isRunning;
    ALLEGRO_DISPLAY* _display;
	b2World* _world;
};

#endif