#include "Vec2.h"

Vec2::Vec2(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vec2f::Vec2f(int x, int y)
{
	this->x = float(x);
	this->y = float(y);
}

Vec2f::Vec2f(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vec2f::Vec2f(const Vec2 & vec2)
{
	this->x = float(vec2.x);
	this->y = float(vec2.y);
}
