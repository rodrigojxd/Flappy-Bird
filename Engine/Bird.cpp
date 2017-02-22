#include "Bird.h"
#include "Level.h"

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
		vy = 10.0f;
	}

	vy -= 1.0f;
	body.pos.y -= int(vy);
	body.pos.y = max(body.pos.y, 0);
	body.pos.y = min(body.pos.y, int(Graphics::ScreenHeight) - body.height);
}

bool Bird::isCollidingWith(const Level & level)
{
	return level.getCollided(body);
}

bool Bird::isOnGround()
{
	return body.pos.y >= int(Graphics::ScreenHeight) - body.height;
}
