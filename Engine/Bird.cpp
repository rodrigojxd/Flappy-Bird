#include "Bird.h"
#include "Level.h"
#include "SpriteCodex.h"

Bird::Bird(const Rect& rect)
{
	this->body = rect;
}

void Bird::Draw(Graphics & gfx)
{
	if (tick <= 10.0f)
		SpriteCodex::DrawBird(body.pos, gfx, 0);
	else if(tick <= 20.0f)
		SpriteCodex::DrawBird(body.pos, gfx, 1);
	else
		SpriteCodex::DrawBird(body.pos, gfx, 2);
	
	if (tick > 30.0f)
	{
		tick = 0.0f;
	}
}

void Bird::Update(float dt)
{
	tick += dt;

	vy += 0.6f * dt;
	body.pos.y += vy * dt;

	//Keep the bird inside the screen
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
		vy = -9.7f;
	}
}
