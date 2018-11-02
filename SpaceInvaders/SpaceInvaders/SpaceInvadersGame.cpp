#include "stdafx.h"
#include "SpaceInvadersGame.h"
#include "Entity.h"
#include <math.h>

#define PLAYER_SPEED 10
#define PROJ_SPEED 12

bool leftPressed = false;
bool rightPressed = false;
bool spacePressed = false;

bool lost = false;

void InputCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

SpaceInvadersGame::SpaceInvadersGame(int width, int height, const char* name) : Game(width, height, name)
{
	// Set the function that is executed upon keypress
	glfwSetKeyCallback(pWindow, InputCallback);

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
}

SpaceInvadersGame::~SpaceInvadersGame()
= default;

void SpaceInvadersGame::RunSpaceInvaders()
{
	float time = 0;
	float enemySpeed = 7;

	Run([=, &time, &enemySpeed]()
	{
		// input
		// move left
		if (leftPressed && player->OutOfBounds() != NEG_X) // a
			player->Move(-PLAYER_SPEED, 0);
		// move right
		if (rightPressed && player->OutOfBounds() != POS_X) // d
			player->Move(PLAYER_SPEED, 0);
		// shoot if the time allows it
		if (spacePressed && time <= 0) // space
		{
			Shoot(&player, projectileTex);
			time = 10.0f;
		}

		// timer decrement
		time -= 0.5f;

		// TODO: handle enemy ai

		// Render
		bg->Draw();
		for (auto enemy : enemies)
		{
			if (enemy->OutOfBounds() == POS_X || enemy->OutOfBounds() == NEG_X)
			{
				// invert direction
				enemySpeed = -enemySpeed;

				// move all enemies a bit to avoid bugs
				for (auto e : enemies)
					e->Move(enemySpeed, -100);
			}
			if (enemy->OutOfBounds() == POS_Y || enemy->CheckCollision(player))
				lost = true;
			// move enemies normally
			enemy->Move(enemySpeed, 0);
			// draw enemies at new position
			enemy->Draw();
		}

		for (int i = 0; i < projectiles.size(); ++i)
		{
			// check if the projectile hit something
			for (int j = 0; j < enemies.size(); ++j)
			{
				if (projectiles[i]->CheckCollision(enemies[j]))
				{
					// erase hit enemy and projectile
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
			if (projectiles[i]->OutOfBounds() == POS_Y)
				projectiles.erase(projectiles.begin() + i);
		}
		player->Draw();

		if (enemies.size() == 0) winScreen->Draw();
		if (lost) loseScreen->Draw();
	});
}

void SpaceInvadersGame::Shoot(const std::shared_ptr<Entity>* player, std::shared_ptr<Sprite> tex)
{
	// create new projectile
	const auto projectile = std::make_shared<Entity>(tex, (*player)->x, (*player)->y);
	// add projectile to render queue
	projectiles.push_back(projectile);
}

// callback executed when a key is pressed
void InputCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// left
	if (key == GLFW_KEY_A)
		leftPressed = action != GLFW_RELEASE;
	// right
	if (key == GLFW_KEY_D)
		rightPressed = action != GLFW_RELEASE;
	// space
	if (key == GLFW_KEY_SPACE)
		spacePressed = action == GLFW_PRESS;
}
