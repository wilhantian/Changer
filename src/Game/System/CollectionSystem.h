#ifndef _COLLECTION_SYSTEM_H_
#define _COLLECTION_SYSTEM_H_

#include "Core/ECS/EntityFu.h"

class CollectionSystem : public System
{
public:
	static void tick(double fixedDelta);
};

#endif