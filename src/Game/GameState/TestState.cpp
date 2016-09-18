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
#include "Game/System/RenderSystem.h"
#include "Game/System/MoveSystem.h"
#include "Game/System/PhysicsSystem.h"
#include "Game/System/ControllerSystem.h"

TestState::TestState()
{
	b2World* world = Game::getInstance()->getWorld();

	{
		b2BodyDef spriteBodyDef;
		spriteBodyDef.type = b2_dynamicBody;
		spriteBodyDef.position.Set(200, 200);

		b2CircleShape circleShape;
		circleShape.m_radius = 20;//设定圆的半径  
		b2FixtureDef bodyFixture;                                           //创建夹具  
		bodyFixture.shape = &circleShape;                                   //设定夹具的形状  

		b2Body* body = world->CreateBody(&spriteBodyDef);
		body->CreateFixture(&bodyFixture);                            //将Body与夹具（Fixtrure）绑定  

		CollisionCom* physics = new CollisionCom(body);

		Entity::create(new VelocityCom(50, 50), new SpriteCom("/Users/wilhantian/Dev/WorkSpace/Changer/res/Sprite-0001.png", 2, 12, 45, 45), new PositionCom(100, 100), physics, new PlayerCom(true));
	}
	
	{
		b2BodyDef spriteBodyDef;
		spriteBodyDef.type = b2_dynamicBody;
		spriteBodyDef.position.Set(400, 400);

		b2CircleShape circleShape;
		circleShape.m_radius = 10;//设定圆的半径  
		b2FixtureDef bodyFixture;                                           //创建夹具  
		bodyFixture.shape = &circleShape;                                   //设定夹具的形状  

		b2Body* body = world->CreateBody(&spriteBodyDef);
		body->CreateFixture(&bodyFixture);                            //将Body与夹具（Fixtrure）绑定  

		CollisionCom* physics = new CollisionCom(body);

		Entity::create(new VelocityCom(-50, -50), new SpriteCom("/Users/wilhantian/Dev/WorkSpace/Changer/res/Sprite-0001.png", 2, 12, 45, 45), new PositionCom(100, 100), physics);
	}
}

TestState::~TestState()
{
	Logger::debug("TestState release.");
}

void TestState::update(float dt)
{
    ControllerSystem::tick(dt);
	PhysicsSystem::tick(dt);
	MoveSystem::tick(dt);
	RenderSystem::tick(dt);
}

void TestState::draw()
{
}