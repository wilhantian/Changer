#include "PhysicsSystem.h"
#include "Box2D/Box2D.h"
#include "Box2D/Box2dRender.h"

void PhysicsSystem::tick(double fixedDelta)
{
	if (!_world)//init
	{
		b2Vec2 gravity(0, -10);
		_world = new b2World(gravity);
	}
}

b2World* PhysicsSystem::_world = nullptr;
