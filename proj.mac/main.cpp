//
//  main.cpp
//  Changer
//
//  Created by WilhanTian on 16/8/8.
//  Copyright © 2016年 WilhanTian. All rights reserved.
//

#include <allegro5/allegro.h>
#include "Framework/Game/Game.h"
#include "Framework/ECS/EntityFu.h"

int main(int argc, char** argv)
{
    Game::getInstance()->run();
    return 0;
}

