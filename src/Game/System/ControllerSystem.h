//
//  PlayerCtrlSystem.h
//  Changer
//
//  Created by WilhanTian on 16/9/14.
//  Copyright © 2016年 WilhanTian. All rights reserved.
//

#ifndef PlayerCtrlSystem_h
#define PlayerCtrlSystem_h

#include "Core/ECS/EntityFu.h"

class ControllerSystem : public System
{
public:
    static void tick(double fixedDelta);
};

#endif /* PlayerCtrlSystem_h */
