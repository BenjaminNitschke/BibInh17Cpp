#pragma once
#include "Game.h"
#include "Sprite.h"
#include <vector>

class FlipoverGame : public Game
{
public:
	FlipoverGame(int width, int height, const char* name);
	~FlipoverGame();
	void RunFlipover();
	void ApplyGravity();
	void Swim();
	void SpawnObstacle(int x);
	void MoveObstacles();
	bool DetectCollision();
	void DrawAll();
private:
	bool GameOver = false;
	int gap = 250;
	int obstacleStart = 700;
	int obstacleRange = 2000;
	int obstacleCount = 4;
	std::shared_ptr<Sprite> background;
	std::shared_ptr<Sprite> endscreen;
	std::shared_ptr<Sprite> fish;
	std::shared_ptr<Texture> obstacleTexture;
	std::vector<std::shared_ptr<Sprite>> obstacles;
};

