//
//  test.hpp
//  Changer
//
//  Created by WilhanTian on 16/8/9.
//  Copyright © 2016年 WilhanTian. All rights reserved.
//

#ifndef test_hpp
#define test_hpp

#include "Framework/ECS/EntityFu.h"

struct PositionComponent : Entity::Component
{
    float x;
    float y;
    
    virtual bool empty()
    {
        return x == 0 && y ==0;
    }
};

#endif /* test_hpp */
