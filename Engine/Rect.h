#pragma once
#include "Vec2.h"

class Rect
{
public:
	int width;
	int height;
	Vec2 pos;
public:
	Rect(int width, int height, const Vec2& pos);
	Rect(const Vec2& dimensions, const Vec2& pos);
	Rect() = default;
};