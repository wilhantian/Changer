#include "PhysicsSystem.h"
#include "Game/Component/ComDefine.h"
#include "Box2D/Box2D.h"
#include "Box2D/Box2dRender.h"

void PhysicsSystem::tick(double fixedDelta)
{
	if (!_world)//init
	{
		b2Vec2 gravity(0, -10);
		_world = new b2World(gravity);
		_world->SetDebugDraw(new Box2dRender());
	}

	auto all = Entity::getAll<PhysicsCom>();
	for (Eid id : all)
	{
		Ent e = Ent(id);
		PhysicsCom& physics = e.physics;
		PositionCom& position = e.position;

		if (!physics.body)//init box2d body
		{
			continue;
		}

		b2Vec2 bodyPos = physics.body->GetPosition();
		position.x = bodyPos.x;
		position.y = bodyPos.y;
	}

	_world->Step(fixedDelta, 6, 2);
	_world->DrawDebugData();
}

b2World* PhysicsSystem::_world = nullptr;
