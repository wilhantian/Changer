#ifndef _BASE_OBJECT_H_
#define _BASE_OBJECT_H_

#define CREATE_FUNC(__TYPE__) \
static __TYPE__* create() \
{ \
__TYPE__ *pRet = new __TYPE__(); \
if (pRet && pRet->init()) \
{ \
pRet->autorelease(); \
return pRet; \
} \
else \
{ \
delete pRet; \
pRet = nullptr; \
return nullptr; \
} \
}

class BaseObject
{
public:
	BaseObject();
	virtual ~BaseObject();

public:
	void retain();
	void release();
	BaseObject* autorelease();
	unsigned int getRefCount();

protected:
	unsigned int _refCount;
};

#endif