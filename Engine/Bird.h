#pragma once
#include "Rect.h"
#include "Graphics.h"
#include "Keyboard.h"

class Bird
{
public:
	Bird(const Rect& rect);
	void Draw(Graphics& gfx);
	void Update(const Keyboard& kbd);
private:
	Rect body;
	static constexpr Color color = Colors::Yellow;
	float vy = 9.89f;
};