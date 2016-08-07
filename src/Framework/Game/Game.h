#ifndef _GAME_H_
#define _GAME_H_

class Game
{
public:
	Game();
	~Game();
	static Game* getInstance();

public:
	void run();

protected:
	static Game* _instance;
};

#endif