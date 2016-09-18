#ifndef _RENDER_COM_H_
#define _RENDER_COM_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>
#include <vector>

#include "Core/ECS/EntityFu.h"

struct RenderCom : Entity::Component
{
	CREATE_CID;

	std::string profile;
	std::vector<ALLEGRO_BITMAP*> frames;
	int curIndex;
	float curDelay;
	float frameRate;
	ALLEGRO_BITMAP* texture;

	RenderCom(std::string profile)
		: profile(profile)
		, curIndex(0)
		, curDelay(0)
		, frameRate(0)
	{
		frameRate = 8;

		int frameSize = 2;
		int width = 45;
		int height = 45;
		std::string filename = "Sprite-0001.png";

		texture = al_load_bitmap((profile + filename).c_str());

		if (texture == nullptr) return;

		int col = al_get_bitmap_width(texture) / width;

		for (int i = 0; i < frameSize; i++)
		{
			ALLEGRO_BITMAP* frame = al_create_sub_bitmap(
				texture, 
				i % col * width, i / col * height,
				width, height);

			if (frame) frames.push_back(frame);
		}
	}

	RenderCom()
		: RenderCom(""){}

	~RenderCom()
	{
		al_destroy_bitmap(texture);
	}

	virtual bool empty() const
	{
		return frames.size() == 0;
	}
};

#endif