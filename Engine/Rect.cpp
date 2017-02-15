#include "Rect.h"

Rect::Rect(int width, int height, const Vec2& pos)
{
	this->width = width;
	this->height = height;
	this->pos = pos;
}

Rect::Rect(const Vec2& dimensions, const Vec2& pos)
{
	this->width = dimensions.x;
	this->height = dimensions.y;
	this->pos = pos;
}