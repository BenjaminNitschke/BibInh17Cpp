#include "stdafx.h"
#include "SpaceInvadersGame.h"
#include "Sprite.h"
#include <memory>
#include <vector>
#include <algorithm>

SpaceInvadersGame::SpaceInvadersGame(int width, int height, const char* name)
{
	background = std::make_shared<Sprite>(std::make_shared<Texture>("background.png"), 1280/2, 720/2);
	ship = std::make_shared<Sprite>(std::make_shared<Texture>("ship.png"), 1280/2, (int)(720*0.9));
	enemies = std::vector<std::shared_ptr<Sprite>>();
	auto enemyTexture = std::make_shared<Texture>("Enemy.png");
	for (float y = 50; y < 150; y += 720/8)
		for (float x = 120; x < 1180; x += 1280/10)
			enemies.push_back(std::make_shared<Sprite>(enemyTexture, x, y));
	missileTexture = std::make_shared<Texture>("Missile.png");
}

SpaceInvadersGame::~SpaceInvadersGame()
{
}

void SpaceInvadersGame::RunSpaceInvaders()
{
	Run([=]()
	{
		ControlShip();
		MoveEnemies();
		DrawAll();
	});
}

void SpaceInvadersGame::ControlShip()
{
	if ((int)(time*1093) % 374 < 4)
		aiMovingRight = !aiMovingRight;
	if (leftPressed || !aiMovingRight)
	{
		if (ship->x > ship->GetWidth())
			ship->Move(-1, 0);
	}
	if (rightPressed || aiMovingRight)
	{
		if (ship->x < 1280 - ship->GetWidth())
			ship->Move(1, 0);
	}
	//always: if (spacePressed && 
	if (lastTimeShot < time - 0.33f)
		FireMissile();
	HandleMissiles();
}

void SpaceInvadersGame::FireMissile()
{
	lastTimeShot = time;
	activeMissiles.push_back(std::make_shared<Sprite>(missileTexture, ship->x, ship->y));
}

void SpaceInvadersGame::HandleMissiles()
{
	activeMissiles.erase(std::remove_if(activeMissiles.begin(), activeMissiles.end(),
		[=](std::shared_ptr<Sprite> missile)
		{
			missile->y -= GetTimeDelta() * 500;
			return missile->y < 0 || CollidingWithEnemyAndKilledIt(missile);
		}),
		activeMissiles.end());
}

bool SpaceInvadersGame::CollidingWithEnemyAndKilledIt(std::shared_ptr<Sprite> missile)
{
	for (auto enemy : enemies)
		if (enemy->DistanceTo(missile, enemiesPosition*100) < 80)
		{
			enemy->y = -1000; // Move out of screen
			return true;
		}
	return false;
}

void SpaceInvadersGame::MoveEnemies()
{
	enemiesPosition += (enemiesMovingRight ? 0.5f : -0.5f) * GetTimeDelta();
	if (enemiesPosition < -0.15f)
		enemiesMovingRight = true;
	if (enemiesPosition > 0.15f)
	{
		enemiesPosition = 0.15f;
		enemiesMovingRight = false;
	}
}

void SpaceInvadersGame::DrawAll()
{
	background->Draw();
	for (auto missile : activeMissiles)
		missile->Draw();
	ship->Draw();
	for (auto enemy : enemies)
		enemy->Draw(enemiesPosition*100);
}