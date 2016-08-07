#include "BaseObject.h"

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
		delete this;
	}
}

unsigned int BaseObject::getRefCount()
{
	return _refCount;
}

