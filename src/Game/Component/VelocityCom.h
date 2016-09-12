#include "Core/ECS/EntityFu.h"
#include <math.h>

/// Velocity Component
struct VelocityCom : Entity::Component
{
	CREATE_CID;

	float x;
	float y;
	
	bool _empty;

	VelocityCom()
		: VelocityCom(0, 0)
	{
		_empty = true;
	}

	VelocityCom(float x, float y)
		: x(x)
		, y(y)
	{
		_empty = false;
	}

	virtual bool empty() const
	{
		return _empty;
	}
};