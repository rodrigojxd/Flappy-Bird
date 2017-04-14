#pragma once
#include "Vec2.h"

class Rect
{
public:
	int width;
	int height;
	Vec2f pos;
public:
	Rect(int width, int height, const Vec2f& pos);
	Rect(const Vec2& dimensions, const Vec2f& pos);
	Rect() = default;
	bool isCollidingWith(const Rect& other) const;
};