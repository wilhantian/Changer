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
#include "Game/System/SpriteSystem.h"
#include "Game/System/PhysicsSystem.h"
#include "Game/Component/ComDefine.h"

TestState::TestState()
{
	b2Vec2 gravity(0, 10);
	b2World* world = new b2World(gravity);
	Box2dRender* debugRender = new Box2dRender();
	uint32 flags = 0;
	flags += b2Draw::e_shapeBit;
	flags += b2Draw::e_jointBit;
	flags += b2Draw::e_centerOfMassBit;
	debugRender->SetFlags(flags);
	world->SetDebugDraw(debugRender);

	PhysicsSystem::world = world;


	PositionCom* posCom = new PositionCom(120, 120);
	SpriteCom* spriteCom = new SpriteCom("E://Changer/res/Sprite-0001.png", 2, 45, 45, 24, 2);

	b2BodyDef bodyDef;
	bodyDef.position.Set(150, 50);
	bodyDef.type = b2_dynamicBody;

	b2Body* body = world->CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsBox(20, 20);

	b2Fixture* fixture = body->CreateFixture(&shape, 24);
	fixture->SetFriction(0.1f);

	PhysicsCom* physics = new PhysicsCom(body);
	Entity::create(posCom, spriteCom, physics);


	{
		b2BodyDef bodyDef;
		bodyDef.position.Set(50, 350);
		//bodyDef.type = b2_dynamicBody;

		b2Body* body = world->CreateBody(&bodyDef);

		b2PolygonShape shape;
		shape.SetAsBox(220, 20);

		b2Fixture* fixture = body->CreateFixture(&shape, 24);
		fixture->SetFriction(0.1f);

		PhysicsCom* physics = new PhysicsCom(body);
		Entity::create(physics);
	}

    Entity::create(new PositionCom(350, 350), new SpriteCom("E://Changer/res/1.png"));
}

TestState::~TestState()
{
	Logger::debug("TestState release.");
}

void TestState::update(float dt)
{
	PhysicsSystem::tick(dt);
	SpriteSystem::tick(dt);
}

void TestState::draw()
{
    
}