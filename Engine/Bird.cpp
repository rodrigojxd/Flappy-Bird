#include "Bird.h"
#include "Level.h"
#include "SpriteCodex.h"

Bird::Bird(const Rect& rect)
{
	this->body = rect;
}

void Bird::Draw(Graphics & gfx)
{
	//gfx.DrawRect(body, color);
	if (tick <= 10)
		SpriteCodex::DrawBird(body.pos.x, body.pos.y, gfx, 0);
	else if(tick <= 20)
		SpriteCodex::DrawBird(body.pos.x, body.pos.y, gfx, 1);
	else if(tick <= 30)
		SpriteCodex::DrawBird(body.pos.x, body.pos.y, gfx, 2);
	tick++;
	if (tick > 30)
	{
		tick = 0;
	}
}

void Bird::Update()
{
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

void Bird::Control(const Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_SPACE))
	{
		vy = 10.0f;
	}
}
