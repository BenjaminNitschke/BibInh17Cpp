#pragma once
#include "Game.h"
#include "Sprite.h"
#include <vector>
#include "Entity.h"

class SpaceInvadersGame : public Game
{
public:
	// background entity
	const std::shared_ptr<Entity> bg = std::make_shared<Entity>("background.png", 1280 / 2, 720 / 2);
	//player entity
	const std::shared_ptr<Entity> player = std::make_shared<Entity>("ship.png", 1280 / 2, 720 * 0.1f);
	// enemy image
	const std::shared_ptr<Sprite> enemyTex = std::make_shared<Sprite>(std::make_shared<Texture>("enemy.png"));
	// projectile image
	const std::shared_ptr<Sprite> projectileTex = std::make_shared<Sprite>(std::make_shared<Texture>("projectile.png"));
	// win screen
	const std::shared_ptr<Entity> winScreen = std::make_shared<Entity>("win.png", 1280 / 2, 720 / 2);

	std::vector<std::shared_ptr<Entity>> projectiles = std::vector<std::shared_ptr<Entity>>();
	std::vector<std::shared_ptr<Entity>> enemies = std::vector<std::shared_ptr<Entity>>();

	SpaceInvadersGame(int width, int height, const char* name);
	~SpaceInvadersGame();
	void RunSpaceInvaders();
	void Shoot(const std::shared_ptr<Entity>* player, std::shared_ptr<Sprite> tex);
};
