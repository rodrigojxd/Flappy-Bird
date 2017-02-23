#pragma once
#include "Tube.h"
#include <random>

class Level
{
private:
	Tube top[4];
	Tube bottom[4];
	static constexpr int vGap = 200;
	static constexpr int hGap = 210;
	std::mt19937 rng;
	unsigned char score = 0;
private:
	void Reset(Tube& tube_top, Tube& tube_bottom, int previous);
public:
	Level();
	void Update(int delta_x);
	void Draw(Graphics& gfx);
	bool getCollided(const Rect& rect) const;
	unsigned char GetScore();
};