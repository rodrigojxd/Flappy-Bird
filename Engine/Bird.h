#pragma once
#include "Rect.h"
#include "Graphics.h"
#include "Keyboard.h"

class Bird
{
public:
	Bird() = default;
	Bird(const Rect& rect);
	void Draw(Graphics& gfx);
	void Update(const Keyboard& kbd);
	bool isCollidingWith(const class Level& level);
	bool isOnGround();
private:
	Rect body;
	static constexpr Color color = Colors::Yellow;
	float vy = 10.0f;
	unsigned char tick = 0;
};