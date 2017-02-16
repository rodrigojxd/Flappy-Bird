#pragma once
#include "Rect.h"
#include "Graphics.h"

class Tube
{
private:
	Rect mouth;
	Rect body;
	int face; // 0: up, 1: down
	static constexpr Color color_mounth = Colors::Green;
	static constexpr Color color_body = Colors::Green;
public:
	Tube(const Vec2& body_dim, const Vec2& mouth_dim, int face, const Vec2& pos);
	void Draw(Graphics& gfx);
	void Update(int delta_x);
};