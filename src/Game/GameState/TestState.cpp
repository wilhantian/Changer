//
//  TestState.cpp
//  Changer
//
//  Created by WilhanTian on 16/8/24.
//  Copyright © 2016年 WilhanTian. All rights reserved.
//

#include "TestState.h"
#include "Game/Component/PositionComp.h"
#include "Game/System/System.h"

bool TestState::init()
{
    if(!GameState::init()){
        return false;
    }
    
    // todo
	Eid a = Entity::create(new PositionComp(20, 20), new SkinComp("E:/Changer/res/1.png"));
	Eid b = Entity::create(new PositionComp(100, 100), new SkinComp("E:/Changer/res/2.jpg"));
    
    return true;
}

void TestState::update(float dt)
{
	RenderSystem::tick(dt);
}

void TestState::draw()
{
    
}