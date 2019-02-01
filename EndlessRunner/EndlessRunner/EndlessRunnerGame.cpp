#include "stdafx.h"
#include "EndlessRunnerGame.h"
#include "Sprite.h"
#include <memory>
#include <algorithm>
#include <ctime>
#include <string>

const int lanes[] = { 270, 525, 764, 1014 };

EndlessRunnerGame::EndlessRunnerGame(int width, int height, const char* name) : Game(width, height, name)
{
	backgroundSpeed = 3;

	playerCar = std::make_shared<Sprite>(std::make_shared<Texture>("../Pics/playerCar.png"), width / 2, height * 0.85f);
	//car01 = std::make_shared<Sprite>(std::make_shared<Texture>("../Pics/car01.png"), width / 2, height * 0.8f);
	//car02 = std::make_shared<Sprite>(std::make_shared<Texture>("../Pics/car02.png"), width / 2, height * 0.8f);
	//car03 = std::make_shared<Sprite>(std::make_shared<Texture>("../Pics/car03.png"), width / 2, height * 0.8f);
	//car04 = std::make_shared<Sprite>(std::make_shared<Texture>("../Pics/car04.png"), width / 2, height * 0.8f);
	//car05 = std::make_shared<Sprite>(std::make_shared<Texture>("../Pics/car05.png"), width / 2, height * 0.8f);

	for (int i = 0; i < 2; i++)
	{
		auto road = std::make_shared<Sprite>(std::make_shared<Texture>("../Pics/road.png"), width / 2, height / 2);
		roads.push_back(road);
	}
	roads[1]->y = -540;

	this->CreateCars(width, height);
}

EndlessRunnerGame::~EndlessRunnerGame()
{
}

void EndlessRunnerGame::ControlCar()
{
	if (leftPressed)
	{
		if (playerCar->x > 160 + playerCar->GetWidth())
			playerCar->Move(-10, 0);
	}
	if (rightPressed)
	{
		if (playerCar->x < 1760 - playerCar->GetWidth())
			playerCar->Move(10, 0);
	}
}

void EndlessRunnerGame::CreateCars(int width, int height)
{
	int index = 0;
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			std::string s;
			s.append("../Pics/car0");
			s.append(std::to_string(i));
			s.append(".png");
			auto car = Car(std::make_shared<Sprite>(std::make_shared<Texture>(s.c_str()), width / 2, height * 0.8f), index, rand() % 5 + 1);
			cars.push_back(car);
			index++;
		}
	}

	for (int i = 0; i < cars.size(); i++)
	{
		this->SpawnCar(cars[i].index);
	}
}

void EndlessRunnerGame::SpawnCar(int index)
{
	cars[index].sprite->x = rand() % (1600 - 2 * cars[index].sprite->GetWidth()) + 160 + cars[index].sprite->GetWidth();
	cars[index].sprite->y = rand() % 2000 - 3080;
}

void EndlessRunnerGame::MoveBackground()
{
	for (int i = 0; i < roads.size(); i++)
	{
		roads[i]->Move(0, backgroundSpeed);

		if (roads[i]->y >= 1620)
		{
			roads[i]->y = -540 + roads[i]->y - 1620;
		}
	}
}

void EndlessRunnerGame::MoveCars()
{
	for (Car car : cars)
	{
		car.sprite->Move(0, car.speed + backgroundSpeed);

		if (car.sprite->y > 1080 + car.sprite->GetHeight())
		{
			SpawnCar(car.index);
		}
	}
}

void EndlessRunnerGame::RunEndlessRunner()
{
	Run([=]()
	{
		ControlCar();
		MoveBackground();
		MoveCars();
		DrawAll();
		backgroundSpeed += 0.5;
	});
}

void EndlessRunnerGame::DrawAll()
{
	for (int i = 0; i < roads.size(); i++)
	{
		roads[i]->Draw();
	}
	for (Car car : cars)
	{
		car.sprite->Draw();
	}

	playerCar->Draw();
}