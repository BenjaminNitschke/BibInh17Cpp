#include "stdafx.h"
#include "SpaceInvadersGame.h"
#include "Sprite.h"
#include <memory>
#include <vector>
#include <algorithm>

SpaceInvadersGame::SpaceInvadersGame(int width, int height, const char* name)
{
	background = std::make_shared<Sprite>(std::make_shared<Texture>("background.png"), 1280 / 2, 720 / 2);
	ship = std::make_shared<Sprite>(std::make_shared<Texture>("ship.png"), 1280 / 2, (int)(720 * 0.9));
	win = std::make_shared<Sprite>(std::make_shared<Texture>("win.png"), 1280 / 2, 720 / 2);
	lose = std::make_shared<Sprite>(std::make_shared<Texture>("lose.png"), 1280 / 2, 720 / 2);
	auto windowWidth = background->texture->width;
	auto windowHeight = background->texture->height;
	enemycount = 20;
	timeBetweenShots = 0;
	enemyMoveTime = 4;
	direction = 1;
	lost = false;

	for (int i = 0; i < enemycount; ++i)
	{
		enemies.push_back(std::make_shared<Sprite>(std::make_shared<Texture>("enemy2.png"), windowWidth * .1f * (i % 10) + 64, i > 9 ? windowHeight * .08 : windowHeight * .18));
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
		if (!lost && enemycount > 0)
		{
			ControlShip();
			MoveEnemies();
			Shoot();
		}
	});
}

void SpaceInvadersGame::DrawAll()
{
	if (enemycount > 0 && !lost)
	{
		background->Draw();
		ship->Draw();
		for (auto enemy : enemies)
		{
			enemy->Draw();
		}
	}
	else if (enemycount > 0 && lost)
	{
		lose->Draw();
	}
	else
	{
		win->Draw();
	}
}

void SpaceInvadersGame::ControlShip()
{
	if (leftPressed)
		ship->Move(-5, 0);
	if (rightPressed)
		ship->Move(5, 0);
}

void SpaceInvadersGame::MoveEnemies()
{
	enemyMoveTime += .25f;
	for (auto enemy : enemies)
	{
		enemy->Move(direction, 0);
		if (enemyMoveTime > 8)
		{
			direction *= -1;
			enemyMoveTime = 0;

			for (auto enemy : enemies)
			{
				enemy->y += 5;
				if (enemy->y > 600)
					lost = true;
			}
		}
	}
}

void SpaceInvadersGame::Shoot()
{
	timeBetweenShots += .5f;

	if (spacePressed && timeBetweenShots > 5)
	{
		missiles.push_back(std::make_shared<Sprite>(std::make_shared<Texture>("missile.png"), ship->x, ship->y - ship->texture->height * .5f));
		timeBetweenShots = 0;
	}

	for (auto missile : missiles)
	{
		missile->Move(0, -10);
		missile->Draw();

		if (CollidingWithAnEnemyAndKilledIt(missile))
		{
			missiles.erase(std::remove(missiles.begin(), missiles.end(), missile), missiles.end());
			enemycount--;
			break;
		}
	}
}

bool SpaceInvadersGame::CollidingWithAnEnemyAndKilledIt(std::shared_ptr<Sprite> missile)
{
	for (auto enemy : enemies)
	{
		if (enemy->DistanceTo(enemy, missile) < 40)
		{
			enemy->y -= 1000000;
			return true;
		}
	}

	return false;
}
