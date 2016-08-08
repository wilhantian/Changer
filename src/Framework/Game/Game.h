#ifndef _GAME_H_
#define _GAME_H_

class Game
{
public:
	Game();
	~Game();
	static Game* getInstance();
    static void destoryInstance();
    
public:
	void run();
    void stop();
protected:
	static Game* _instance;
};

#endif