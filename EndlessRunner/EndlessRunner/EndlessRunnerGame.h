#pragma once
#include <Game.h>
#include <Sprite.h>
#include <vector>
#include "Entity.h"
#include "EndlessRunner.h"

class EndlessRunnerGame : public Game
{
public:
	EndlessRunnerGame(int width, int height, const char* name);
	~EndlessRunnerGame();
	void CreateEntities(std::string path, int differentEntities, int amountPerEntity, int with, int height, int minSpeed, int maxSpeed, std::vector<Entity>* v);
	void SpawnEntity(std::vector<Entity> entity, int index, int xPos, int yPos);
	void SpawnAllEntities();
	void RunEndlessRunner();
	void DetectPlayerCollision();
	void DetectNpcCollision();
	bool DetectCollision(Entity e1, Entity e2);
	void DrawAll();
	void ControlCar();
	void MoveBackground();
	void MoveEntity();
	float backgroundSpeed;
	float playerSpeed;

private:
	std::shared_ptr<Sprite> playerCar;
	std::vector<std::shared_ptr<Sprite>> roads;
	std::vector<Entity> cars;
	std::vector<Entity> trees;
	std::shared_ptr<Sprite> gameOver;
	bool dead = false;
};

