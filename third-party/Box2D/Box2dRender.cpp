//
//  Box2dRender.cpp
//  Changer
//
//  Created by WilhanTian on 16/9/2.
//  Copyright © 2016年 WilhanTian. All rights reserved.
//

#include "Box2dRender.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

/// Draw a closed polygon provided in CCW order.
void Box2dRender::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	for (int32 i = 1; i < vertexCount; i++)
	{
		DrawSegment(vertices[i - 1], vertices[i], color);
	}
	DrawSegment(vertices[vertexCount - 1], vertices[0], color);
}

/// Draw a solid closed polygon provided in CCW order.
void Box2dRender::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	DrawPolygon(vertices, vertexCount, color);
}

/// Draw a circle.
void Box2dRender::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{
	al_draw_circle(center.x, center.y, radius, al_map_rgb(color.r, color.g, color.b), 3);
}

/// Draw a solid circle.
void Box2dRender::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
{
	al_draw_circle(center.x, center.y, radius, al_map_rgb(color.r, color.g, color.b), 3);
    
    // Draw the axis line
    DrawSegment(center,center+radius*axis,color);
}

/// Draw a line segment.
void Box2dRender::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	al_draw_line(p1.x, p1.y, p2.x, p2.y, al_map_rgb(color.r, color.g, color.b), 3);
}

/// Draw a transform. Choose your own length scale.
/// @param xf a transform.
void Box2dRender::DrawTransform(const b2Transform& xf)
{
}

/// Draw a point.
void Box2dRender::DrawPoint(const b2Vec2& p, float32 size, const b2Color& color)
{
	DrawCircle(p, size, color);
}