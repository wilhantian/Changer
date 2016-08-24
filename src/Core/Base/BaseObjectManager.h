#ifndef _BASE_OBJECT_MANAGER_H_
#define _BASE_OBJECT_MANAGER_H_

#include "BaseObject.h"
#include <queue>

class BaseObjectManager
{
public:
	BaseObjectManager();
	~BaseObjectManager();
	static BaseObjectManager* getInstance();
	static void destoryInstance();

public:
	void add(BaseObject* obj);
	void clear();

private:
	static BaseObjectManager* _instance;
	std::queue<BaseObject*> _objects;
};

#endif