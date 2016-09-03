//
//  Box2dRender.hpp
//  Changer
//
//  Created by WilhanTian on 16/9/2.
//  Copyright © 2016年 WilhanTian. All rights reserved.
//

#ifndef Box2dRender_h
#define Box2dRender_h

#include <stdio.h>

#include "Common/b2Draw.h"

class Box2dRender : public b2Draw
{
public:
    /// Draw a closed polygon provided in CCW order.
    virtual void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
    
    /// Draw a solid closed polygon provided in CCW order.
    virtual void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
    
    /// Draw a circle.
    virtual void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
    
    /// Draw a solid circle.
    virtual void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
    
    /// Draw a line segment.
    virtual void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
    
    /// Draw a transform. Choose your own length scale.
    /// @param xf a transform.
    virtual void DrawTransform(const b2Transform& xf);
    
    /// Draw a point.
    virtual void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color);
};


#endif /* Box2dRender_h */
