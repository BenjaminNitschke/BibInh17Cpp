#include "stdafx.h"
#include "EndlessRunnerGame.h"
#include "Sprite.h"
#include <memory>
#include <algorithm>

const float width = 1920;
const float height = 1080;

EndlessRunnerGame::EndlessRunnerGame(int width, int height, const char* name) : Game(width, height, name)
{
	road = std::make_shared<Sprite>(std::make_shared<Texture>("../Pics/road.png"), width / 2, height / 2);
	playerCar = std::make_shared<Sprite>(std::make_shared<Texture>("../Pics/playerCar.png"), width / 2, height * 0.8f);
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
	playerCar->Draw();
	road->Draw();
	
}