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
    
    MoveCom(float speed, kDirection direction, Vector position)
        : speed(speed)
        , direction(direction)
        , position(position) {}
    
    MoveCom()
        : MoveCom(0, kDirection::Down, Vector(0, 0)){}
    
	virtual bool empty() const
	{
		return false;
	}
};

#endif