#ifndef _VECTOR_H_
#define _VECTOR_H_

class Vector
{
public:
	Vector();
	Vector(float x, float y);
	~Vector();

public:
	inline void set(float xx, float yy);

	void set(const float* array);

	inline void set(const Vector& v);

	inline void setZero();

public:
	float x;
	float y;
};

#endif