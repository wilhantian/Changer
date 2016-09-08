//
//  TestState.hpp
//  Changer
//
//  Created by WilhanTian on 16/8/24.
//  Copyright © 2016年 WilhanTian. All rights reserved.
//

#ifndef _TestState_h_
#define _TestState_h_

#include <stdio.h>
#include "Core/ECS/EntityFu.h"
#include "Core/GameState/GameState.h"

class TestState : public GameState
{   
public:
	TestState();
	virtual ~TestState();
    
    int b;
    
public:
    virtual void update(float dt);
    virtual void draw();
};

#endif /* _TestState_h_ */
