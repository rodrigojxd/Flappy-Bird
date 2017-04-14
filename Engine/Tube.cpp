#include "Tube.h"

Tube::Tube(const Vec2& body_dim, const Vec2& mouth_dim, Face face, const Vec2& pos)
{
	this->face = face;
	if (face == Face::Down)
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

void Tube::Update(float dt)
{
	mouth.pos.x -= dt;
	body.pos.x -= dt;
}

bool Tube::isCollidingWith(const Rect & rect) const
{
	return mouth.isCollidingWith(rect) || body.isCollidingWith(rect);
}

float Tube::GetExtremeLeftX() const
{
	return mouth.pos.x;
}

float Tube::GetExtremeRightX() const
{
	return mouth.pos.x + mouth.width;
}
