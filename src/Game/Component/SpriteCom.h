#ifndef _RENDER_COMP_H_
#define _RENDER_COMP_H_

#include <vector>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Core/ECS/EntityFu.h"

enum SpriteType
{
	Static,//¾²Ì¬
	Anime//Ö¡¶¯»­
};

struct SpriteCom : Entity::Component
{
	static Cid cid;

	float x = 0;
	float y = 0;
	float w = 0;
	float h = 0;
	SpriteType spriteType = SpriteType::Static;
    std::string fileName;
	float frameRate = 0;
	float curFrameDelay = 0;
	ALLEGRO_BITMAP* curFrame = nullptr;
	std::vector<ALLEGRO_BITMAP*> frames;
    
	SpriteCom()
	{
	}

	SpriteCom(float x, float y, float w, float h) :
		x(x),
		y(y),
		w(w),
		h(h)
	{
	}

	SpriteCom(float x, float y, float w, float h, std::vector<ALLEGRO_BITMAP*> frames, float frameRate) :
		x(x),
		y(y),
		w(w),
		h(h),
		frames(frames),
		frameRate(frameRate)
	{
	}

	virtual bool empty() const
	{
		return false;
	}
};

#endif //_RENDER_COMP_H_