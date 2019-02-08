#include "stdafx.h"
#include "EndlessRunnerGame.h"
#include "Sprite.h"
#include <memory>
#include <algorithm>
#include <string>
#include <windows.h>
#include <mmsystem.h>

const int collisionTolerance = 12;

EndlessRunnerGame::EndlessRunnerGame(int width, int height, const char* name) : Game(width, height, name)
{
	backgroundSpeed = 3;
	playerSpeed = 10;

	playerCar = std::make_shared<Sprite>(std::make_shared<Texture>("../Pics/playerCar.png"), width / 2, height * 0.85f);
	gameOver = std::make_shared<Sprite>(std::make_shared<Texture>("../Pics/GameOver2.png"), width / 2, height / 2);

	for (int i = 0; i < 2; i++)
	{
		auto road = std::make_shared<Sprite>(std::make_shared<Texture>("../Pics/road.png"), width / 2, height / 2);
		roads.push_back(road);
	}
	roads[1]->y = -540;

	CreateEntities("../Pics/car0", 5, 3, width, height, 1, 5, &cars);
	CreateEntities("../Pics/tree0", 2, 2, width, height, 0, 0, &trees);

	SpawnAllEntities();
}

EndlessRunnerGame::~EndlessRunnerGame()
{
}

void EndlessRunnerGame::ControlCar()
{
	if (leftPressed || aPressed)
	{
		if (playerCar->x > 160 + playerCar->GetWidth())
			playerCar->Move(-playerSpeed, 0);
	}
	if (rightPressed || dPressed)
	{
		if (playerCar->x < 1760 - playerCar->GetWidth())
			playerCar->Move(playerSpeed, 0);
	}
	if (hPressed)
	{
		PlaySound(TEXT("../Pics/honk.wav"), nullptr, SND_FILENAME | SND_ASYNC);
		hPressed = false;
	}		
}

void EndlessRunnerGame::CreateEntities(std::string path, int differentEntities, int amountPerEntity, int width, int height, int minSpeed, int maxSpeed, std::vector<Entity>* v) 
{
	int index = 0;
	for (int i = 1; i <= differentEntities; i++)
	{
		for (int j = 0; j < amountPerEntity; j++)
		{
			const auto speed = maxSpeed == 0 ? 0 : minSpeed + rand() % maxSpeed;
			std::string s;
			s.append(path);
			s.append(std::to_string(i));
			s.append(".png");
			auto entity = Entity(std::make_shared<Sprite>(std::make_shared<Texture>(s.c_str()), width, height), index, speed);
			v->push_back(entity);
			index++;
		}
	}
}

void EndlessRunnerGame::SpawnEntity(std::vector<Entity> entity, int index, int xPos, int yPos)
{
	if (entity[index].speed > 0)
		cars[index].speed = 1 + rand() % 5;
	entity[index].sprite->x = xPos;
	entity[index].sprite->y = yPos;
}

void EndlessRunnerGame::SpawnAllEntities()
{
	for (int i = 0; i < cars.size(); i++)
	{
		SpawnEntity(cars, i, rand() % (1600 - 2 * cars[i].sprite->GetWidth()) + 160 + cars[i].sprite->GetWidth(), rand() % 2000 - 3080);
	}

	for (int i = 0; i < trees.size(); i++)
	{		
		if (i % 2)
			SpawnEntity(trees, i, 100, i * -900 - 200);
		else
			SpawnEntity(trees, i, 1820, (i - 2) * -400 - 200);
	}
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

void EndlessRunnerGame::MoveEntity()
{
	for (Entity car : cars)
	{
		car.sprite->Move(0, car.speed + backgroundSpeed);

		if (car.sprite->y > 1080 + car.sprite->GetHeight())
		{
			SpawnEntity(cars, car.index, rand() % (1600 - 2 * car.sprite->GetWidth()) + 160 + car.sprite->GetWidth(), rand() % 2000 - 3080);
		}
	}

	for (Entity tree : trees)
	{
		tree.sprite->Move(0, tree.speed + backgroundSpeed);

		if (tree.sprite->y > 1080 + tree.sprite->GetHeight())
		{
			SpawnEntity(trees, tree.index, tree.sprite->x, rand() % 400 - 1080);
		}
	}
}

void EndlessRunnerGame::DetectPlayerCollision()
{
	for (Entity enemy : cars)
	{
		if (playerCar->x < enemy.sprite->x + enemy.sprite->GetWidth() - collisionTolerance &&
			playerCar->x + playerCar->GetWidth() - collisionTolerance > enemy.sprite->x &&
			playerCar->y < enemy.sprite->y + enemy.sprite->GetHeight() - collisionTolerance &&
			playerCar->y + playerCar->GetHeight() - 2 * collisionTolerance > enemy.sprite->y)
		{
			dead = true;
			PlaySound(TEXT("../Pics/crash.wav"), nullptr, SND_FILENAME | SND_ASYNC);
			return;
		}
	}
}

void EndlessRunnerGame::DetectNpcCollision()
{
	for (auto i = 0; i < cars.size(); i++)
	{
		for (auto j = 0; j < cars.size(); j++)
		{
			if (i == j) continue;
			if (DetectCollision(cars[i], cars[j]))
			{
				if (cars[i].sprite->y > cars[j].sprite->y)
				{
					cars[j].speed = cars[i].speed;
					cars[j].sprite->y -= 5;
				}
				else
				{
					cars[i].speed = cars[j].speed;
					cars[i].sprite->y -= 5;
				}
			}
		}
	}
}

bool EndlessRunnerGame::DetectCollision(Entity e1, Entity e2)
{
	return e1.sprite->x < e2.sprite->x + e2.sprite->GetWidth() &&
		e1.sprite->x + e1.sprite->GetWidth() > e2.sprite->x &&
		e1.sprite->y < e2.sprite->y + e2.sprite->GetHeight() &&
		e1.sprite->y + e1.sprite->GetHeight() > e2.sprite->y;
}

void EndlessRunnerGame::RunEndlessRunner()
{
	Run([=]()
	{
		if (dead)
		{
			gameOver->Draw();
			return;
		}
		ControlCar();
		MoveBackground();
		MoveEntity();
		DrawAll();
		DetectPlayerCollision();
		DetectNpcCollision();
		backgroundSpeed += 0.002;
		playerSpeed += 0.001;
	});
}

void EndlessRunnerGame::DrawAll()
{
	for (int i = 0; i < roads.size(); i++)
	{
		roads[i]->Draw();
	}
	for (Entity car : cars)
	{
		car.sprite->Draw();
	}
	for (Entity tree : trees)
	{
		tree.sprite->Draw();
	}

	playerCar->Draw();
}