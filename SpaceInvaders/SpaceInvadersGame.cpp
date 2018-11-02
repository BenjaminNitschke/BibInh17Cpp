#include "stdafx.h"
#include "SpaceInvadersGame.h"
#include "Sprite.h"
#include <memory>
#include <vector>

SpaceInvadersGame::SpaceInvadersGame(int width, int height, const char* name)
{
	background = std::make_shared<Sprite>(std::make_shared<Texture>("background.png"), 1280/2, 720/2);
	ship = std::make_shared<Sprite>(std::make_shared<Texture>("ship.png"), 1280/2, (int)(720*0.9));
	auto enemyTexture = std::make_shared<Texture>("enemy.png");
	enemies = std::vector<std::shared_ptr<Sprite>>();
	
	//amout of enemies and there position
	int x = 120;
	int y = 83;
	for (int j = 0; j < 16; j++)
	{
		enemies.push_back(std::make_shared<Sprite>(enemyTexture, x, y));
		x += 150;

		if (x >= 1200)
		{
			x = 120;
			y += 100;
		}
	}
}

SpaceInvadersGame::~SpaceInvadersGame()
{
}

void SpaceInvadersGame::RunSpaceInvaders()
{
	Run([=]()
	{
		DrawAll();
		ControlShip();
		MoveEnemies();
	});
}

void SpaceInvadersGame::ControlShip()
{
	if (leftPressed)
		ship->Move(-1, 0);
	if (rightPressed)
		ship->Move(1, 0);
}

void SpaceInvadersGame::MoveEnemies()
{
	int speed = 0;
	int counter = 0;
	//TODO later: handle enemy ai, move enemies
	for (int i = 0; i < enemies.size(); i++)
	{
		//FIX IT!!!
		if (counter <= 3)
		{
			speed = 1;
			counter ++;
		}
		else if (counter > 3)
		{
			speed = -1;
			counter ++;
			if (counter >= 6)
			{
				counter = 0;
			}
		}

		enemies[i]->Move(speed, 0);
		/*enemies[i]->Move(1, 0);*/
	}
}

void SpaceInvadersGame::DrawAll()
{
	background->Draw();
	ship->Draw();
	for (int i = 0; i < 16; i++)
	{
		enemies[i]->Draw();
	}	
}