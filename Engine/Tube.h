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
	void Update(float dt);
	bool isCollidingWith(const Rect& rect) const;
	float GetExtremeLeftX() const;
	float GetExtremeRightX() const;
	bool birdPassed = false;
};