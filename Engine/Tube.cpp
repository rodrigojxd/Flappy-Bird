#include "Tube.h"

Tube::Tube(const Vec2& body_dim, const Vec2& mouth_dim, const Vec2& pos)
	: 
	mouth(mouth_dim, {pos.x - (mouth_dim.x - body_dim.x)/2, pos.y + body_dim.y}),
	body(body_dim, pos)
{
}

void Tube::Draw(Graphics& gfx)
{
	gfx.DrawRect(mouth, color_mounth);
	gfx.DrawRect(body, color_body);
}
