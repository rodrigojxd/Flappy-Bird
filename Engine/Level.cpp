#include "Level.h"

Level::Level()
	:
	rng(std::random_device()())
{
	
	for (int i = 0; i < 4; ++i)
	{
		Reset(top[i], bottom[i], i);
	}
}

void Level::Update(int delta_x)
{
	for (int i = 0; i < 4; ++i)
	{
		top[i].Update(delta_x);
		bottom[i].Update(delta_x);
		if (top[i].GetExtremeLeftX() < 0) {
			Reset(top[i], bottom[i], 0);
		}
	}
}

void Level::Draw(Graphics & gfx)
{
	for (int i = 0; i < 4; ++i)
	{
		top[i].Draw(gfx);
		bottom[i].Draw(gfx);
	}
}

void Level::Reset(Tube& tube_top, Tube& tube_bottom, int previous)
{
	std::uniform_int_distribution<int> dist(100, 500 - vGap);
	const int top_size = dist(rng);
	tube_top = Tube({ 30, top_size }, { 36, 15 }, 1, { 800 + previous * hGap, 0 });
	tube_bottom = Tube({ 30, 600 - vGap - top_size }, { 36, 15 }, 0, { 800 + previous * hGap, vGap + top_size - 15 });
}

bool Level::getCollided(const Rect & rect) const
{
	bool collided = false;
	for (int i = 0; i < 4; ++i)
	{
		collided = collided || top[i].isCollidingWith(rect);
		collided = collided || bottom[i].isCollidingWith(rect);
	}
	return collided;
}
