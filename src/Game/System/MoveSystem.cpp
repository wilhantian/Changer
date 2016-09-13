#include "MoveSystem.h"
#include "Core/Logger/Logger.h"
#include "Game/Component/ComDefine.h"

void MoveSystem::tick(double fixedDelta)
{
	auto all = Entity::getAll<VelocityCom>();
	for (Eid id : all)
	{
		Ent e(id);
		VelocityCom& velocity = e.velocity;
		PositionCom& position = e.position;
		PhysicsCom& physics = e.physics;

		IF_COM_NULL_CONTINUE(velocity);
		IF_COM_NULL_CONTINUE(position);

		if (physics.empty())
		{
			position.x += velocity.x * fixedDelta;
			position.y += velocity.y * fixedDelta;
		}
		else
		{
			position.x = physics.body->GetPosition().x;
			position.y = physics.body->GetPosition().y;
		}
	}
}
