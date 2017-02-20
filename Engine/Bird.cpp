#include "Bird.h"

Bird::Bird(const Rect& rect)
{
	this->body = rect;
}

void Bird::Draw(Graphics & gfx)
{
	gfx.DrawRect(body, color);
}

void Bird::Update(const Keyboard & kbd)
{
	if (kbd.KeyIsPressed(VK_SPACE))
	{
		vy = 9.89f;
	}

	vy -= 1.0f;
	body.pos.y -= int(vy);

	int ground = 600 - body.height;

	if (body.pos.y >= ground)
	{
		//TODO: Game over
	}
}
