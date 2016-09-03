#ifndef _PHYSICS_COM_H_
#define _PHYSICS_COM_H_

#include "Core/ECS/EntityFu.h"

struct PhysicsCom : Entity::Component
{
	CREATE_CID;

	virtual bool empty() const
	{
		return false;
	}
};

#endif//_PHYSICS_COM_H_