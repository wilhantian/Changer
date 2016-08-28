//
//  TestState.cpp
//  Changer
//
//  Created by WilhanTian on 16/8/24.
//  Copyright © 2016年 WilhanTian. All rights reserved.
//

#include "TestState.h"
#include "Game/System/System.h"
#include "Game/System/SpriteSystem.h"
#include "Core/Logger/Logger.h"

TestState::TestState()
{
	// todo
// 	Eid a = Entity::create(new PositionComp(20, 20), new SkinComp("E:/Changer/res/1.png"));
// 	Eid b = Entity::create(new PositionComp(100, 100), new SkinComp("E:/Changer/res/2.jpg"));
    
	//Entity::destroyNow(a);
	//Entity::destroyNow(b);
}

TestState::~TestState()
{
	Logger::debug("TestState release.");
}

void TestState::update(float dt)
{
	RenderSystem::tick(dt);
	SpriteSystem::tick(dt);
}

void TestState::draw()
{
    
}