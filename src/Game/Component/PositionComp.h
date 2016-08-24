//
//  PositionComp.hpp
//  Changer
//
//  Created by WilhanTian on 16/8/24.
//  Copyright © 2016年 WilhanTian. All rights reserved.
//

#ifndef PositionComp_h
#define PositionComp_h

#include <stdio.h>
#include "Core/ECS/EntityFu.h"
#include <allegro5/allegro.h>

struct PositionComp : Entity::Component
{
	static Cid cid;
	float x = 0;
	float y = 0;

	PositionComp() : PositionComp(0, 0){}

	PositionComp(float x, float y):
		x(x),
		y(y)
	{
	}

	virtual bool empty() const
	{
		return false;
	}
};

struct SkinComp : Entity::Component
{
	static Cid cid;
	const char* name;
	ALLEGRO_BITMAP* bitmap;

	SkinComp() : SkinComp(name){}

	SkinComp(const char* name):
		name(name),
		bitmap(nullptr)
	{

	}

	virtual bool empty() const
	{
		return false;
	}
};



/// 系统容器
struct System::Ent
{
	Eid id;
	PositionComp& position;
	SkinComp& skin;
	/// 这里添加其他组件

	Ent(Eid _id) :
		position(Entity::get<PositionComp>(_id)),
		skin(Entity::get<SkinComp>(_id)),
		id(_id)
	{}
};

#endif /* PositionComp_hpp */
