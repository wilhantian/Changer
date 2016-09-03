#ifndef _VELOCITY_COM_H_
#define _VELOCITY_COM_H_

#include "Core/ECS/EntityFu.h"

struct VelocityCom : Entity::Component
{
	CREATE_CID;

	float vx;
	float vy;

	VelocityCom()
		: vx(0)
		, vy(0)
	{
	}

	virtual bool empty() const
	{
		return false;
	}
};

#endif//_VELOCITY_COM_H_