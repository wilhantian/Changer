#include "Vector.h"

Vector::Vector():
x(0),
y(0)
{

}

Vector::Vector(float x, float y):
x(x),
y(y)
{

}

Vector::~Vector()
{

}

void Vector::set(float xx, float yy)
{
	x = xx;
	y = yy;
}

void Vector::set(const float* array)
{
	x = array[0];
	y = array[1];
}

void Vector::set(const Vector& v)
{
	x = v.x;
	y = v.y;
}

void Vector::setZero()
{
	x = y = 0;
}

