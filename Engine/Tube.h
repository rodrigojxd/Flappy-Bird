#pragma once
#include "Rect.h"
#include "Graphics.h"

class Tube
{
public:
	enum Face
	{
		Up,
		Down
	};
private:
	Rect mouth;
	Rect body;
	Face face;
	static constexpr Color color_mounth = Colors::Green;
	static constexpr Color color_body = Colors::Green;
public:
	Tube() = default;
	Tube(const Vec2& body_dim, const Vec2& mouth_dim, Face face, const Vec2& pos);
	void Draw(Graphics& gfx);
	void Update(int delta_x);
	bool isCollidingWith(const Rect& rect) const;
	int GetExtremeLeftX() const;
	int GetExtremeRightX() const;
	bool birdPassed = false;
};