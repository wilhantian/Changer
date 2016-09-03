//
//  TestState.cpp
//  Changer
//
//  Created by WilhanTian on 16/8/24.
//  Copyright © 2016年 WilhanTian. All rights reserved.
//

#include "TestState.h"
#include "Core/Logger/Logger.h"
#include "Game/System/System.h"
#include "Game/System/SpriteSystem.h"
#include "Game/Component/ComDefine.h"

TestState::TestState()
{
    
	PositionCom* posCom = new PositionCom(120, 120);
	SpriteCom* spriteCom = new SpriteCom("E://Changer/res/Sprite-0001.png", 2, 45, 45, 24, 2);
    Entity::create(posCom, spriteCom);

    Entity::create(new PositionCom(350, 350), new SpriteCom("E://Changer/res/1.png"));
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