#pragma once
#include <Game.h>
#include <Sprite.h>

class EndlessRunnerGame : public Game
{
public:
	EndlessRunnerGame(int width, int height, const char* name);
	~EndlessRunnerGame();
	void RunEndlessRunner();
	void DrawAll();

private:
	std::shared_ptr<Sprite> road;
	std::shared_ptr<Sprite> playerCar;
};

