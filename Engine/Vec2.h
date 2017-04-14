#pragma once

class Vec2
{
public:
	int x;
	int y;
public:
	Vec2() = default;
	Vec2(int x, int y);
};

class Vec2f
{
public:
	float x;
	float y;
public:
	Vec2f() = default;
	Vec2f(int x, int y);
	Vec2f(float x, float y);
	Vec2f(const Vec2& vec2);
};