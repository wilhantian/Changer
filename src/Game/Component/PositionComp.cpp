//
//  PositionComp.cpp
//  Changer
//
//  Created by WilhanTian on 16/8/24.
//  Copyright © 2016年 WilhanTian. All rights reserved.
//

#include "PositionComp.h"

static Cid _id = 0;
Cid PositionComp::cid = _id++;
Cid SkinComp::cid = _id++;
Cid Entity::Component::numCids = _id;