#ifndef _MOVE_COM_H_
#define _MOVE_COM_H_

#include "Core/ECS/EntityFu.h"
#include "Core/Math/Vector.h"
#include "Game/common.h"

struct MoveCom : Entity::Component
{
	CREATE_CID;

	float speed;
	kDirection direction;
	Vector position;

	virtual bool empty() const
	{
		return false;
	}
};

#endif