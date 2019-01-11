#include "stdafx.h"
#include "EndlessRunnerGame.h"
#include "Sprite.h"
#include <memory>
#include <algorithm>

EndlessRunnerGame::EndlessRunnerGame(int width, int height, const char* name) : Game(width, height, name)
{
	road = std::make_shared<Sprite>(std::make_shared<Texture>("../Pics/road.png"), 1920 / 2, 1080 / 2);
	road->x = 0;
	road->y = 0;
}

EndlessRunnerGame::~EndlessRunnerGame()
{
}

void EndlessRunnerGame::RunEndlessRunner() 
{
	Run([=]()
	{
		DrawAll();
	});
}

void EndlessRunnerGame::DrawAll()
{
	road->Draw();
}