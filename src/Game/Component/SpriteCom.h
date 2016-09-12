#include "Core/ECS/EntityFu.h"

#include <allegro5/allegro5.h>
#include <vector>

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
	{
		if (filename.empty() || size <= 0 || width <= 0 || height <= 0 || index < 0)
			return;

		ALLEGRO_BITMAP* texture = al_load_bitmap(filename.c_str());	

		if (!texture)
			return;

		int tw = al_get_bitmap_width(texture);
		int th = al_get_bitmap_height(texture);
		int col = tw / width;
		int row = th / height;

		for (int i = 0; i < size; i++)
		{
			ALLEGRO_BITMAP* frame = al_create_sub_bitmap(
				texture, 
				i % col, i / row, //TODO
				width, height);
			frames.push_back(frame);
		}
	}

	~SpriteCom()
	{
// 		if (texture)
// 		{
// 			al_destroy_bitmap(texture);
// 			texture = NULL;
// 		}
	}

	virtual bool empty() const
	{
		return frames.size() == 0;
	}
};