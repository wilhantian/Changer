#include "Core/ECS/EntityFu.h"

#include <allegro5/allegro5.h>
#include <vector>
#include <string>

struct SpriteCom : Entity::Component
{
	CREATE_CID;

	int size;
	int index;
	int rate;
	int width;
	int height;
	std::string filename;
	ALLEGRO_BITMAP* curFrame;
	std::vector<ALLEGRO_BITMAP*> frames;

	float delay;
	ALLEGRO_BITMAP* texture;

	SpriteCom()
		: SpriteCom("", 0, 0, 0, 0)
	{
	}

	SpriteCom(std::string filename, int size, int rate, int width, int height, int index = 0)
		: filename(filename)
		, size(size)
		, rate(rate)
		, width(width)
		, height(height)
		, index(index)
		, delay(0)
	{
		if (filename.empty() || size <= 0 || width <= 0 || height <= 0 || index < 0)
			return;

		texture = al_load_bitmap(filename.c_str());	

		if (!texture)
			return;

		int tw = al_get_bitmap_width(texture);
		int col = tw / width;

		for (int i = 0; i < size; i++)
		{
			ALLEGRO_BITMAP* frame = al_create_sub_bitmap(
				texture, 
				i % col * width, i / col * height,
				width, height);
			frames.push_back(frame);
		}

		curFrame = frames[index];
	}

	~SpriteCom()
	{
		for (auto frame : frames)
		{
			al_destroy_bitmap(frame);
		}
		al_destroy_bitmap(texture);
	}

	virtual bool empty() const
	{
		return frames.size() == 0;
	}
};