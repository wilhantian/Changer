#include "SpriteCom.h"

SpriteCom::SpriteCom()
	: spriteType(SpriteType::None)
{
}

SpriteCom::SpriteCom(std::string filename)
	: spriteType(SpriteType::Static)
	, filename(filename)
{
}

SpriteCom::SpriteCom(std::string filename, int frameSize, int frameWidth, int frameHeight, float frameRate, int frameCol)
	: spriteType(SpriteType::Anime)
	, filename(filename)
	, frameSize(frameSize)
	, frameWidth(frameWidth)
	, frameHeight(frameHeight)
	, frameRate(frameRate)
	, frameCol(frameCol)
{
}

bool SpriteCom::empty() const
{
	return bitmap == nullptr;
}



