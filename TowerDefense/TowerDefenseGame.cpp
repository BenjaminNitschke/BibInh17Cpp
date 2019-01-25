#include "stdafx.h"
#include "TowerDefenseGame.h"
#include "Sprite.h"
#include <memory>
#include <vector>

TowerDefenseGame::TowerDefenseGame(int width, int height, const char* name)
{
	background = std::make_shared<Sprite>(std::make_shared<Texture>("background.png"), 1280 / 2, 720 / 2);
	slot = std::make_shared<Texture>("slot.png");
	for (int x = 0; x < 16; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			slots.push_back(*(new Sprite(slot, x * 80 + 40, y * 80 + 40)));
		}
	}
	//ship = std::make_shared<Sprite>(std::make_shared<Texture>("ship.png"), 1280 / 2, (int)(720 * 0.9));
	//std::shared_ptr<Texture> enemyTexture = std::make_shared<Texture>("enemy.png");
	//missile = std::make_shared<Texture>("missle.png");

	frames = 0;
	enemyDir = 1;
	enemySpeed = 1;
	enemyH = 0;

	//TODO: enemyTexture and 20 * enemies in 2 rows
	/*for (int i = 0; i < 20; i++)
	{
		enemies.push_back(*(new Sprite(enemyTexture, 1280 / 11 * ((i % 10) + 1) - 16,(int)(720 * 0.1 * ((i / 10) + 1)))));
	}*/
}

TowerDefenseGame::~TowerDefenseGame()
{
}

void TowerDefenseGame::RunSpaceInvaders()
{
	Run([=]()
	{
		//ControlMissles();
		//ControlShip();
		//MoveEnemies();
		DrawAll();
		frames++;
	});
}

void TowerDefenseGame::ControlMissles()
{
	for (int i = 0; i < missiles.size(); i++)
	{
		Sprite* tmpMissile = &missiles.at(i);
		tmpMissile->Move(0, -1);
	}

	for (auto missile : missiles)
	{
		for (auto enemie : enemies)
		{
			if (DistanceTo(&missile, &enemie) < 0.05f)
			{
				(&missile)->setPos(0, -1000);
				//missiles.erase(&missile);
				(&enemie)->setPos(0, -1000);
				//enemies.erase(&enemie);
			}
		}
	}
}

void TowerDefenseGame::ControlShip()
{
	if (leftPressed) ship->Move(-2, 0);
	if (rightPressed) ship->Move(2, 0);
	
	if (spacePressed && glfwGetTime() - lastTimeShoot > 0.4)
	{
		missiles.push_back(*(new Sprite(missile, ship->getPos(0), ship->getPos(1))));
		lastTimeShoot = glfwGetTime();
	}
}

void TowerDefenseGame::MoveEnemies()
{
	if (frames % 1000 == 0) enemyDir = 1;
	if (frames % 1000 == 500) enemyDir = -1;
	if (frames % 2000 == 1000) enemyH = 10;
	else enemyH = 0;

	double time = glfwGetTime();

	if (frames % 15 == 0)
		for (int i = 0; i < 20; i++)
		{
			Sprite *enemy = &enemies.at(i);
			enemy->Move(enemyDir * enemySpeed, enemyH * 10);
		}
}

void TowerDefenseGame::DrawAll()
{
	background->Draw();
	for (int i = 0; i < slots.size(); i++)
	{
		Sprite *tmp = &slots.at(i);
		tmp->Draw();
	}
	/*ship->Draw();
	for (int i = 0; i < 20; i++)
	{
		Sprite *tmp = &enemies.at(i);
		tmp->Draw();
	}
	for (int i = 0; i < missiles.size(); i++)
	{
		Sprite *tmp = &missiles.at(i);
		tmp->Draw();
	}*/
}

double TowerDefenseGame::DistanceTo(Sprite* missile, Sprite* enemie)
{
	double x = missile->getPos(0) - enemie->getPos(0);
	double y = missile->getPos(1) - enemie->getPos(1);
	return sqrt((x*x) + (y*y));
}