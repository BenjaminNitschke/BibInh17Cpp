#pragma once
#include <Game.h>
#include <Sprite.h>
#include <time.h>
#include <vector>
#include "Car.h"

class EndlessRunnerGame : public Game
{
public:
	EndlessRunnerGame(int width, int height, const char* name);
	~EndlessRunnerGame();
	void RunEndlessRunner();
	void DrawAll();
	void ControlCar();
	void CreateCars(int width, int height);
	void CreateTrees(int width, int height);
	void SpawnCar(int index);
	void SpawnTree();
	void MoveBackground();
	void MoveCars();
	float backgroundSpeed;

private:
	std::shared_ptr<Sprite> playerCar;
	std::vector<std::shared_ptr<Sprite>> roads;
	std::vector<Car> cars;
	std::vector<std::shared_ptr<Sprite>> trees;
};

