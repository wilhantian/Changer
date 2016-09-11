#ifndef _RENDER_COMP_H_
#define _RENDER_COMP_H_

#include <vector>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Core/ECS/EntityFu.h"

enum SpriteType
{
	None,
	Static,//just have one image/frames
	Anime//have some frame
};

struct SpriteCom : Entity::Component
{
	CREATE_CID;

	SpriteType spriteType = SpriteType::None;
	ALLEGRO_BITMAP* bitmap = nullptr;
	std::string filename;
	float x;
	float y;
	int frameSize = 0;
	int frameWidth = 0;
	int frameHeight = 0;
	int frameCol = 0;
	float frameRate = 0;
	float curFrameDelay = 0;
	int curFrame = 0;
    
	SpriteCom();

	/// Static
	SpriteCom(std::string filename);

	/// Anime
	SpriteCom(std::string filename
		, int frameSize, int frameWidth, int frameHeight, float frameRate, int frameCol);

	virtual bool empty() const;
   
};

#endif //_RENDER_COMP_H_