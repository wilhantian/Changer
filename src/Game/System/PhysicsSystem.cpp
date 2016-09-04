#include "PhysicsSystem.h"
#include "Game/Component/ComDefine.h"
#include "Box2D/Box2D.h"
#include "Box2D/Box2dRender.h"

void PhysicsSystem::tick(double fixedDelta)
{
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

	world->Step(fixedDelta, 6, 2);
	world->DrawDebugData();
}

b2World* PhysicsSystem::world = nullptr;
