#ifndef _POSITION_COM_H_
#define _POSITION_COM_H_

#include "Core/ECS/EntityFu.h"

struct PositionCom : Entity::Component
{
	static Cid cid;

	float x;
	float y;

	PositionCom()
		: PositionCom(0, 0)
	{
	}

	PositionCom(float x, float y)
		: x(x)
		, y(y)
	{
	}

	virtual bool empty() const
	{
		return false;
	}
};

#endif//_POSITION_COM_H_