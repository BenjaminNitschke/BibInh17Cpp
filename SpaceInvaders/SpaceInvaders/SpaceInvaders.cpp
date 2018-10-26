#include "stdafx.h"
#include "SpaceInvaders.h"
#include "SpaceInvadersGame.h"
#include "Texture.h"
#include "Sprite.h"
#include <memory>
#include <vector>
#include "Entity.h"

#define PLAYER_SPEED 10
#define PROJ_SPEED 12
#define TIME 10

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	// an instance of the base game
	const auto game = std::make_shared<SpaceInvadersGame>(1280, 720, "Space Invaders");
	// background entity
	const auto bg = std::make_shared<Entity>("background.png", 1280/2,720/2);
	//player entity
	const auto player = std::make_shared<Entity>("ship.png", 1280/2, 720 * 0.1f);
	// enemy image
	const auto enemyTex = std::make_shared<Sprite>(std::make_shared<Texture>("enemy.png"));
	// projectile image
	const auto projectileTex = std::make_shared<Sprite>(std::make_shared<Texture>("projectile.png"));
	// shooting timer
	float time = 0;
	

	// y-position of every enemy in first row
	float yOffset = 720 * 0.9;

	for (int i = 0; i < 2; ++i)
	{
		// x-position of first enemy in every row
		float xOffset = 360;
		for (int j = 0; j < 10; ++j) {
			// add new enemy to current row
			enemies.push_back(std::make_shared<Entity>(enemyTex, xOffset, yOffset));
			// next enemy is further to the right
			xOffset += 60;
		}
		// next enemy is further down
		yOffset -= 80;
	}

	game->Run([=, &time]()
	{
		// input
		// move left
		if(glfwGetKey(game->pWindow, 65) && player->OutOfBounds() != NEG_X) // a
			player->Move(-PLAYER_SPEED, 0);
		// move right
		if (glfwGetKey(game->pWindow, 68) && player->OutOfBounds() != POS_X) // d
			player->Move(PLAYER_SPEED, 0);
		// shoot if the time allows it
		if (glfwGetKey(game->pWindow, 32) && time <= 0) // space
		{
			Shoot(&player, projectileTex);
			time = 10.0f;
		}

		// timer decremnt
		time -= 0.5f;

		// TODO: handle enemy ai

		// Render
		bg->Draw();
		for (auto enemy : enemies)
			enemy->Draw();
		for(int i = 0; i < projectiles.size(); ++i)
		{
			// check if the projectile hit something
			for(int j = 0; j < enemies.size(); ++j)
			{
				if(projectiles[i]->CheckCollision(enemies[j]))
				{
					enemies.erase(enemies.begin() + j);
					projectiles.erase(projectiles.begin() + i);
					break;
				}
			}
			if (projectiles.size() == 0) break;
			projectiles[i]->Draw();
			// move projectile
			projectiles[i]->Move(0, PROJ_SPEED);
			// delete projectile if off the screen
			if(projectiles[i]->OutOfBounds() == POS_Y)
				projectiles.erase(projectiles.begin() + i);
		}
		player->Draw();

		
	});
	return 0;
}

void Shoot(const std::shared_ptr<Entity>* player, std::shared_ptr<Sprite> tex)
{
	// create new projectile
	const auto projectile = std::make_shared<Entity>(tex, (*player)->x, (*player)->y);
	// add projectile to render queue
	projectiles.push_back(projectile);
}