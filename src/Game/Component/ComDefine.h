#ifndef _COM_DEFINE_H_
#define _COM_DEFINE_H_

#include "Core/ECS/EntityFu.h"
#include "Core/Base/utils.h"

#include "Game/Component/PositionCom.h"
#include "Game/Component/VelocityCom.h"
#include "Game/Component/SpriteCom.h"
#include "Game/Component/CollisionCom.h"
#include "Game/Component/PlayerCom.h"

/// please register in .cpp
struct System::Ent
{
	Eid id;
	// BEGIN
	PositionCom& position;
	VelocityCom& velocity;
	SpriteCom& sprite;
	CollisionCom& physics;
    PlayerCom& player;
	// END

	Ent(Eid _id);
};

#endif //_COM_DEFINE_H_