//
//  Box2dRender.cpp
//  Changer
//
//  Created by WilhanTian on 16/9/2.
//  Copyright © 2016年 WilhanTian. All rights reserved.
//

#include "Box2dRender.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_opengl.h>

/// Draw a closed polygon provided in CCW order.
void Box2dRender::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
    glColor4f(color.r, color.g, color.g, 1);
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
}

/// Draw a solid closed polygon provided in CCW order.
void Box2dRender::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    
    glColor4f(color.r, color.g, color.b, 1);
    glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);
    
    glColor4f(color.r, color.g, color.b, 1);
    glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
}

/// Draw a circle.
void Box2dRender::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{
    const float32 k_segments = 16.0f;
    int vertexCount=16;
    const float32 k_increment = 2.0f * b2_pi / k_segments;
    float32 theta = 0.0f;
    
    GLfloat				glVertices[vertexCount*2];
    for (int32 i = 0; i < k_segments; ++i)
    {
        b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
        glVertices[i*2]=v.x;
        glVertices[i*2+1]=v.y;
        theta += k_increment;
    }
    
    glColor4f(color.r, color.g, color.b,1);
    glVertexPointer(2, GL_FLOAT, 0, glVertices);
    
    glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);
}

/// Draw a solid circle.
void Box2dRender::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
{
    const float32 k_segments = 16.0f;
    int vertexCount=16;
    const float32 k_increment = 2.0f * b2_pi / k_segments;
    float32 theta = 0.0f;
    
    GLfloat				glVertices[vertexCount*2];
    for (int32 i = 0; i < k_segments; ++i)
    {
        b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
        glVertices[i*2]=v.x;
        glVertices[i*2+1]=v.y;
        theta += k_increment;
    }
    
    glColor4f(color.r, color.g, color.b,0.5f);
    glVertexPointer(2, GL_FLOAT, 0, glVertices);
    glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);
    glColor4f(color.r, color.g, color.b,1);
    glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
    
    // Draw the axis line
    DrawSegment(center,center+radius*axis,color);
}

/// Draw a line segment.
void Box2dRender::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
    glColor4f(color.r, color.g, color.b,1);
    GLfloat				glVertices[] = {
        p1.x,p1.y,p2.x,p2.y
    };
    glVertexPointer(2, GL_FLOAT, 0, glVertices);
    glDrawArrays(GL_LINES, 0, 2);

}

/// Draw a transform. Choose your own length scale.
/// @param xf a transform.
void Box2dRender::DrawTransform(const b2Transform& xf)
{
//    b2Vec2 p1 = xf.p, p2;
//    const float32 k_axisScale = 0.4f;
//    
//    p2 = p1 + k_axisScale * xf.q.s;
//    DrawSegment(p1,p2,b2Color(1,0,0));
//    
//    p2 = p1 + k_axisScale * xf.q.c;
//    DrawSegment(p1,p2,b2Color(0,1,0));
}

/// Draw a point.
void Box2dRender::DrawPoint(const b2Vec2& p, float32 size, const b2Color& color)
{
    glColor4f(color.r, color.g, color.b,1);
    glPointSize(size);
    GLfloat				glVertices[] = {
        p.x,p.y
    };
    glVertexPointer(2, GL_FLOAT, 0, glVertices);
    glDrawArrays(GL_POINTS, 0, 1);
    glPointSize(1.0f);
}