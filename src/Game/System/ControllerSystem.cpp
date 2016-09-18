//
//  PlayerCtrlSystem.cpp
//  Changer
//
//  Created by WilhanTian on 16/9/14.
//  Copyright © 2016年 WilhanTian. All rights reserved.
//

#include "ControllerSystem.h"

#include <allegro5/allegro.h>

#include "Core/Game/Game.h"
#include "Game/Component/ComDefine.h"

void ControllerSystem::tick(double fixedDelta)
{
    ALLEGRO_KEYBOARD_STATE state;
    al_get_keyboard_state(&state);
    if(al_key_down(&state, ALLEGRO_KEY_A))
    {
        auto all = Entity::getAll<PlayerCom>();
        for(Eid id : all)
        {
            Ent e(id);
            VelocityCom& velocity = e.velocity;
            
            IF_COM_NULL_CONTINUE(velocity);
            
            velocity.x = 0;
            velocity.y = 10;
        }
    }
    else
    {
        auto all = Entity::getAll<PlayerCom>();
        for(Eid id : all)
        {
            Ent e(id);
            VelocityCom& velocity = e.velocity;
            
            IF_COM_NULL_CONTINUE(velocity);
            velocity.x = 0;
            velocity.y = 0;
        }
    }
}