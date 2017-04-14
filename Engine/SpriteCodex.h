#pragma once

#include "Graphics.h"

class SpriteCodex
{
public:
	static void DrawGameOver( int x,int y,Graphics& gfx );
	static void DrawScoreBoard(int x, int y, Graphics& gfx);
	static void DrawNumber(unsigned char number, int x, int y, Graphics& gfx);
	static void DrawPressToStart(int x, int y, Graphics& gfx);
	static void DrawBird(int x, int y, Graphics& gfx, unsigned char frame);
	static void DrawBird(const Vec2f& pos, Graphics& gfx, unsigned char frame)
	{
		DrawBird(int(pos.x), int(pos.y), gfx, frame);
	}
};