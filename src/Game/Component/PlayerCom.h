//
//  PlayerCom.h
//  Changer
//
//  Created by WilhanTian on 16/9/14.
//  Copyright © 2016年 WilhanTian. All rights reserved.
//

#ifndef PlayerCom_h
#define PlayerCom_h

#include "Core/ECS/EntityFu.h"

struct PlayerCom : Entity::Component
{
    CREATE_CID;
    
    bool enable;
    
    PlayerCom()
        : PlayerCom(false)
    {
        
    }
    
    PlayerCom(bool enable)
        : enable(enable)
    {
    }
    
    virtual bool empty() const
    {
        return !enable;
    }
};

#endif /* PlayerCom_h */
