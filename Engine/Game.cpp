/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	sound_hit(L"Sounds\\hit.wav"),
	sound_point(L"Sounds\\point.wav")
{
	Reset();
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark() * 60; //delta time
	switch (gameState)
	{
	case Playing:
	{
		level.Update(dt * 2);
		bird.Control(wnd.kbd);
		bird.Update(dt);
		unsigned char score_new = std::min(int(level.GetScore()), 99);
		if (score_new > score)
			sound_point.Play(1.0f, 0.3f);
		score = score_new;
		break;
	}
	case NotStarted:
	case GameOver:
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			Reset();
			gameState = Playing;
		}
		break;
	}
	case NoControl:
	{
		level.Update(dt * 2);
		bird.Update(dt);
		break;
	}
	}
	if (bird.isCollidingWith(level) && gameState == Playing)
	{
		gameState = NoControl;
		sound_hit.Play(1.0f, 0.3f);
	}
	if (bird.isOnGround() && gameState != GameOver)
	{
		gameState = GameOver;
		sound_hit.Play(1.0f, 0.3f);
	}
}

void Game::Reset()
{
	level = Level();
	bird = Bird({ 34, 24,{ 200, 200 } });
}

void Game::DrawScore(unsigned char score)
{
	SpriteCodex::DrawScoreBoard(10, 10, gfx);
	SpriteCodex::DrawNumber(score / 10, 120, 10, gfx); //tens
	SpriteCodex::DrawNumber(score % 10, 137, 10, gfx); //units
}

void Game::ComposeFrame()
{
	switch (gameState)
	{
	case Playing:
	case NoControl:
		level.Draw(gfx);
		DrawScore(score);
		break;
	case GameOver:
		SpriteCodex::DrawGameOver(235, 250, gfx);
		DrawScore(score);
		break;
	case NotStarted:
		SpriteCodex::DrawPressToStart(160, 250, gfx);
		break;
	}
	bird.Draw(gfx);
}
