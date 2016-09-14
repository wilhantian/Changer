#include "PhysicsSystem.h"
#include "Core/Game/Game.h"
#include "Game/Component/ComDefine.h"

void PhysicsSystem::tick(double fixedDelta)
{
	auto all = Entity::getAll<CollisionCom>();
	for (Eid id : all)
	{
		Ent e(id);
		CollisionCom& physics = e.physics;
		VelocityCom& velocity = e.velocity;

		IF_COM_NULL_CONTINUE(physics);

		if (!velocity.empty())
		{
			physics.body->ApplyLinearImpulseToCenter(b2Vec2(velocity.x, velocity.y), true);
		}
	}

	b2World* world = Game::getInstance()->getWorld();
	world->Step(fixedDelta, 6, 2);
	world->DrawDebugData();
}

