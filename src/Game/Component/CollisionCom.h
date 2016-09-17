#ifndef _COLLISION_COM_H_
#define _COLLISION_COM_H_

#include "Core/ECS/EntityFu.h"
#include "Core/Math/Size.h"

struct CollisionCom : Entity::Component
{
	CREATE_CID;

	Size size;
	int filterCategory;
	int filterMask;

	CollisionCom(const Size& size, int filterCategory, int filterMask)
		: size(size)
		, filterCategory(filterCategory)
		, filterMask(filterMask){}

	CollisionCom()
		: size(0, 0)
		, filterCategory(0)
		, filterMask(0){}

	virtual bool empty() const
	{
	}
};

#endif