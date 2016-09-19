//
//  TestState.cpp
//  Changer
//
//  Created by WilhanTian on 16/8/24.
//  Copyright © 2016年 WilhanTian. All rights reserved.
//

#include "TestState.h"
#include <allegro5/allegro_primitives.h>
#include "Box2D/Box2D.h"
#include "Core/Game/Game.h"
#include "Core/Logger/Logger.h"
#include "Core/Event/EventWh.h"

#include "Game/Component/ComDefine.h"
#include "Game/System/InputSystem.h"
#include "Game/System/MoveSystem.h"
#include "Game/System/RenderSystem.h"
#include "Game/System/CollectionSystem.h"

TestState::TestState()
{
	Eid e = Entity::create();
	Entity::addComponent(e, new RenderCom(""));
	Entity::addComponent(e, new MoveCom(130, kDirection::Down, Vector(200, 200)));
	Entity::addComponent(e, new CollectionCom(Size(30, 14), Vector(5, 28), 1, 1));
}

TestState::~TestState()
{
	Logger::debug("TestState release.");
}

void TestState::update(float dt)
{
	InputSystem::tick(dt);
	MoveSystem::tick(dt);
	CollectionSystem::tick(dt);
	RenderSystem::tick(dt);
}

void TestState::draw()
{
}