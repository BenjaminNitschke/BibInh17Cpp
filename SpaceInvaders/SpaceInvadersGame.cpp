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
	enemies.push_back(std::make_shared<Sprite>(enemyTexture, 720, 83));
	//TODO: enemyTexture and 20 * enemies in 2 rows
}

SpaceInvadersGame::~SpaceInvadersGame()
{
}

void SpaceInvadersGame::RunSpaceInvaders()
{
	Run([=]()
	{
		//TODO later: handle enemy ai, move enemies
		background->Draw();
		if (leftPressed)
			ship->Move(-1, 0);
		if (rightPressed)
			ship->Move(1, 0);
		ship->Draw();
		//TODO: draw enemies
		enemies[0]->Draw();
	});
}