#ifndef _BODY_COM_H_
#define _BODY_COM_H_

#include "Core/ECS/EntityFu.h"
#include "Box2d/Box2D.h"

struct BodyCom : Entity::Component
{
	CREATE_CID;

	b2Body* body;

	BodyCom()
		:BodyCom(nullptr)
	{
	}

	BodyCom(b2Body* body)
		:body(body)
	{
	}

	virtual bool empty() const
	{
		return false;
	}
};

#endif