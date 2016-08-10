#include "BaseObjectManager.h"
#include "Logger.h"

BaseObjectManager::BaseObjectManager()
{
}

BaseObjectManager::~BaseObjectManager()
{
}

BaseObjectManager* BaseObjectManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new BaseObjectManager();
	}
	return _instance;
}

void BaseObjectManager::destoryInstance()
{
	if (_instance)
	{
		delete _instance;
	}
}

void BaseObjectManager::add(BaseObject* obj)
{
	if (!obj)
	{
		Logger::warn("your add a null object in BaseObjectManager");
		return;
	}

	_objects.push(obj);
}

void BaseObjectManager::clear()
{
	int size = _objects.size();
	for (int i = 0; i < size; i++)
	{
		BaseObject* obj = _objects.front();
		
		if (obj)
			obj->release();

		_objects.pop();
	}
}

BaseObjectManager* BaseObjectManager::_instance = nullptr;
