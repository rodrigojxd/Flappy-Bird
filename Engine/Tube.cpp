#include "Tube.h"

Tube::Tube(const Vec2& body_dim, const Vec2& mouth_dim, int face, const Vec2& pos)
{
	this->face = face;
	if (face == 1)
	{
		mouth = Rect(mouth_dim, { pos.x - (mouth_dim.x - body_dim.x) / 2, pos.y + body_dim.y });
		body = Rect(body_dim, pos);
	}
	else
	{
		mouth = Rect(mouth_dim, { pos.x - (mouth_dim.x - body_dim.x) / 2, pos.y});
		body = Rect(body_dim, {pos.x, pos.y + mouth_dim.y });
	}
}

void Tube::Draw(Graphics& gfx)
{
	gfx.DrawRect(mouth, color_mounth);
	gfx.DrawRect(body, color_body);
}

void Tube::Update(int delta_x)
{
	mouth.pos.x -= delta_x;
	body.pos.x -= delta_x;
}

bool Tube::isCollidingWith(const Rect & rect) const
{
	return mouth.isCollidingWith(rect) || body.isCollidingWith(rect);
}

int Tube::GetExtremeLeftX() const
{
	return mouth.pos.x + mouth.width;
}
