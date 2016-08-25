#ifndef _GRAPICS_H_
#define _GRAPICS_H_

#include <allegro5/allegro.h>
#include <map>

class Grapics
{
public:
	static ALLEGRO_BITMAP* loadImage(std::string& imageFile);

	static void releaseImage(std::string& imageFile);
	static void releaseImage(ALLEGRO_BITMAP* imageFile);

	static void destroyImage(std::string& imageFile);
	static void destroyImage(ALLEGRO_BITMAP* imageFile);

private:
	static std::map<std::string, std::string> _bitmaps;
};

#endif //_GRAPICS_H_