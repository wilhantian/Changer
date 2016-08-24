#include "BaseObject.h"
#include "BaseObjectManager.h"
#include "Core/Logger/Logger.h"

BaseObject::BaseObject():
_refCount(1)
{
}

BaseObject::~BaseObject()
{
}

void BaseObject::retain()
{
	++_refCount;
}

void BaseObject::release()
{
	--_refCount;
	if (_refCount == 0)
	{
		//Logger::debug("release : %d", this);
		delete this;
	}
}

BaseObject* BaseObject::autorelease()
{
	BaseObjectManager::getInstance()->add(this);
	return this;
}

unsigned int BaseObject::getRefCount()
{
	return _refCount;
}

