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

bool Rect::isCollidingWith(const Rect & other) const
{
	return pos.x + width > other.pos.x && pos.x < other.pos.x + other.width &&
		pos.y + height > other.pos.y && pos.y < other.pos.y + other.height;
}
