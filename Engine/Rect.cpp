#include "Rect.h"

Rect::Rect(float top, float bottom, float left, float right)
{
	this->top = top;
	this->bottom = bottom;
	this->left = left;
	this->right = right;
}

Rect::Rect(const Vec2 & topLeft, const Vec2 & bottomRight)
{
	this->top = topLeft.y;
	this->bottom = bottomRight.y;
	this->left = topLeft.x;
	this->right = bottomRight.x;
}