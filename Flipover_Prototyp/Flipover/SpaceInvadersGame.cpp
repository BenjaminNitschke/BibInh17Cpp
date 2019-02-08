#include "stdafx.h"
#include "SpaceInvadersGame.h"
#include "Sprite.h"
#include <memory>
#include <vector>
#include "AudioManager.h"

FlipoverGame::FlipoverGame(int width, int height, const char* name)
{
	background = std::make_shared<Sprite>(std::make_shared<Texture>("OceanBackground.png"), windowWidth / 2, windowHeight / 2);
	fish = std::make_shared<Sprite>(std::make_shared<Texture>("Fish.png"), (int)(windowWidth * 0.1), windowHeight / 2);
	obstacles = std::vector<std::shared_ptr<Sprite>>();
	obstacleTexture = std::make_shared<Texture>("Obstacle.png");
	endscreen = std::make_shared<Sprite>(std::make_shared<Texture>("GameOverScreen.png"), windowWidth / 2, windowHeight / 2);
	for (float x = obstacleStart; x <= (obstacleRange + obstacleStart); x += (obstacleRange / obstacleCount))
	{
		SpawnObstacle(x);
	}
}

FlipoverGame::~FlipoverGame()
{
}

void FlipoverGame::RunFlipover()
{

	sf::Music music;
	music.openFromFile("BFGDivision.ogg");

	music.play();

	Run([=]()
	{
		if (!GameOver)
		{
			Swim();
			ApplyGravity();
			MoveObstacles();
			DetectCollision();
			DrawAll();
		}
		else 
		{
			endscreen->Draw();
		}
	});
}

void FlipoverGame::Swim()
{
	if (spacePressed && fish->y > 0 + (fish->GetHeight()/2))
	{
		fish->Move(0, -1.2f);
	}
}

void FlipoverGame::ApplyGravity()
{
	if (!spacePressed && fish->y < windowHeight - (fish->GetHeight()/2))
	{
		fish->Move(0, 0.8f);
	}
}

void FlipoverGame::SpawnObstacle(int x)
{
	int y = 0;
	y = rand() % (700 - gap) - 360;
	obstacles.push_back(std::make_shared<Sprite>(obstacleTexture, x, y));
	y += (windowHeight + gap);
	obstacles.push_back(std::make_shared<Sprite>(obstacleTexture, x, y));
}

void FlipoverGame::MoveObstacles()
{
	int y;
	for (int i = 0; i < obstacles.size(); i+=2)
	{
		obstacles.at(i)->Move(-0.5f, 0);
		obstacles.at(i + 1)->Move(-0.5f, 0);
		if (obstacles.at(i)->x < (0-obstacles.at(i)->GetWidth()/2) && obstacles.at(i + 1)->x < (0 - obstacles.at(i + 1)->GetWidth() / 2))
		{
			y = 0;
			obstacles.at(i)->x = 2700;
			y = rand() % (700 - gap) - 360;
			obstacles.at(i)->y = y;
			obstacles.at(i + 1)->x = 2700;
			y += (windowHeight + gap);
			obstacles.at(i + 1)->y = y;
		}
	}
}

bool FlipoverGame::DetectCollision() 
{
	for (int i = 0; i < obstacles.size(); i += 2)
	{
		if (abs(obstacles.at(i)->y - fish->y) < (obstacles.at(i)->GetHeight() / 2 + (fish->GetHeight()-35) / 2) && abs(obstacles.at(i)->x - fish->x) < (obstacles.at(i)->GetWidth() / 2 + fish->GetWidth() / 2) || abs(obstacles.at(i + 1)->y - fish->y) < (obstacles.at(i + 1)->GetHeight() / 2 + (fish->GetHeight()-35) / 2) && abs(obstacles.at(i + 1)->x - fish->x) < (obstacles.at(i + 1)->GetWidth() / 2 + fish->GetWidth() / 2))
		{ 
			GameOver = true;
			return true;
		}
		GameOver = false;
	}
	return false;
}

void FlipoverGame::DrawAll()
{
	background->Draw();
	fish->Draw();
	for (auto obstacle : obstacles)
		obstacle->Draw();
}