#ifndef _COLLISION_COM_H_
#define _COLLISION_COM_H_

#include "Core/ECS/EntityFu.h"
#include "Core/Math/Size.h"
#include "Core/Math/Vector.h"

struct CollectionCom : Entity::Component
{
	CREATE_CID;

	Size size;
	Vector offset;
	int filterCategory;
	int filterMask;

	CollectionCom(const Size& size, const Vector& offset, int filterCategory, int filterMask)
		: size(size)
		, offset(offset)
		, filterCategory(filterCategory)
		, filterMask(filterMask){}

	CollectionCom()
		: size(0, 0)
		, filterCategory(0)
		, filterMask(0){}

	virtual bool empty() const
	{
		return false;
	}
};

#endif