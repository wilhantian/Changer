#ifndef _COM_DEFINE_H_
#define _COM_DEFINE_H_

#include "Core/ECS/EntityFu.h"
#include "SpriteCom.h"
#include "PositionCom.h"
#include "VelocityCom.h"
#include "PhysicsCom.h"

/// 组件在.cpp中注册
/// 预定义系统组件
struct System::Ent
{
	Eid id;
	// BEGIN
	SpriteCom& sprite;
	PositionCom& position;
	VelocityCom& velocity;
	PhysicsCom& physics;
	// END

	Ent(Eid _id);
};

#endif //_COM_DEFINE_H_