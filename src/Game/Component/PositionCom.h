#ifndef _POSITION_COM_H_
#define _POSITION_COM_H_

#include "Core/ECS/EntityFu.h"
#include "Box2D/Box2D.h"

struct PositionCom : Entity::Component
{
	CREATE_CID;

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