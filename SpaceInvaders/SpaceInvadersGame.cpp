#include "stdafx.h"
#include "SpaceInvadersGame.h"
#include "Sprite.h"
#include <memory>
#include <vector>



SpaceInvadersGame::SpaceInvadersGame(int width, int height, const char* name)
{
	background = std::make_shared<Sprite>(std::make_shared<Texture>("background.png"), 1280 / 2, 720 / 2);
	ship = std::make_shared<Sprite>(std::make_shared<Texture>("ship.png"), 1280 / 2, (int)(720 * 0.9));
	std::shared_ptr<Texture> enemyTexture = std::make_shared<Texture>("enemy.png");

	frames = 0;
	enemyDir = 1;
	enemySpeed = 1;
	enemyH = 0;

	//TODO: enemyTexture and 20 * enemies in 2 rows
	for (int i = 0; i < 20; i++)
	{
		enemies.push_back(*(new Sprite(enemyTexture, 1280 / 11 * ((i % 10) + 1) - 16,(int)(720 * 0.1 * ((i / 10) + 1)))));
	}
}

SpaceInvadersGame::~SpaceInvadersGame()
{
}

void SpaceInvadersGame::RunSpaceInvaders()
{
	Run([=]()
	{
		//TODO later: handle input, control player ship
		if (leftPressed) ship->Move(-4, 0);
		if (rightPressed) ship->Move(4, 0);

		//TODO later: handle enemy ai, move enemies
		
		if (frames % 1000 == 0) enemyDir = 1;
		if (frames % 1000 == 500) enemyDir = -1;
		if (frames % 2000 == 1000) enemyH = 10;
		else enemyH = 0;

		double time = glfwGetTime();

		if(frames % 15 == 0)
		for (int i = 0; i < 20; i++)
		{
			Sprite *enemy = &enemies.at(i);
			enemy->Move(enemyDir * enemySpeed, enemyH * 10);
		}
		


		background->Draw();
		ship->Draw();
		//TODO: draw enemies
		for (int i = 0; i < 20; i++)
		{
			Sprite *enemy = &enemies.at(i);
			enemy->Draw();
		}
		frames++;
	});
}
