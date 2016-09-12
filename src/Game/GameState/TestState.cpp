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
#include "Box2D/Box2dRender.h"
#include "Core/Logger/Logger.h"
#include "Game/Component/ComDefine.h"
#include "Core/Event/EventWh.h"

TestState::TestState()
{
}

TestState::~TestState()
{
	Logger::debug("TestState release.");
}

void TestState::update(float dt)
{
}

void TestState::draw()
{
    
}