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
	void Update(float dt);
	bool isCollidingWith(const class Level& level);
	bool isOnGround();
	void Control(const Keyboard& kbd);
private:
	Rect body;
	static constexpr Color color = Colors::Yellow;
	float vy = -9.7f;
	float tick = 0.0f;
};