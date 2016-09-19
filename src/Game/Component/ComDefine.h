#ifndef _COM_DEFINE_H_
#define _COM_DEFINE_H_

#include "Core/ECS/EntityFu.h"
#include "Core/Base/utils.h"
#include "Game/Component/MoveCom.h"
#include "Game/Component/RenderCom.h"
#include "Game/Component/CollectionCom.h"

/// please register in .cpp
struct System::Ent
{
	Eid id;

	// BEGIN
	MoveCom& move;
	RenderCom& render;
	CollectionCom& collection;
	// END

	Ent(Eid _id);
};

#endif //_COM_DEFINE_H_