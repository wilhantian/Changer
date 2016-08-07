#ifndef _BASE_OBJECT_H_
#define _BASE_OBJECT_H_

class BaseObject
{
public:
	BaseObject();
	~BaseObject();

public:
	void retain();
	void release();
	unsigned int getRefCount();

protected:
	unsigned int _refCount;
};

#endif