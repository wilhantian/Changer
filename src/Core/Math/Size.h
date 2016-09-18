#ifndef _SIZE_H_
#define _SIZE_H_

struct Size
{
	float width;
	float height;

	Size(float width, float height)
		: width(width)
		, height(height)
	{
	}
};

#endif