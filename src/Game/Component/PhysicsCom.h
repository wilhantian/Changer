#ifndef _PHYSICS_COM_H_
#define _PHYSICS_COM_H_

#include "Core/ECS/EntityFu.h"
#include "Box2D/Box2D.h"

struct PhysicsCom : Entity::Component
{
	CREATE_CID;

	b2Body* body;

	PhysicsCom()
		:PhysicsCom(nullptr)
	{
	}

	PhysicsCom(b2Body* body)
		:body(body)
	{
	}

	virtual bool empty() const
	{
		return false;
	}
};

#endif//_PHYSICS_COM_H_