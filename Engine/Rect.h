#pragma once
#include "Vec2.h"

class Rect
{
public:
	float top;
	float bottom;
	float left;
	float right;
public:
	Rect(float top, float bottom, float left, float right);
	Rect(const Vec2& topLeft, const Vec2& bottomRight);
};