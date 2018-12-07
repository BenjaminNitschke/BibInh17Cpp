#pragma once
#include "Game.h"
#include <memory>
#include "Sprite.h"
#include "Vector3.h"

class FpsGame : public Game
{
public:
	FpsGame(int width, int height, const char* name);
	~FpsGame();
	float Xrotation = 0;
	float Yrotation = 0;
	Vector3 movement = Vector3(0, 0, 0);
	float MovementSpeed = 0.023f;
	void RunGame();
	void SetupProjection() const;
	void UpdateCamera() const;
	void Input();
	const float DegreeToRadians = (1.0f / 180.0f) * 3.14159f;
	std::shared_ptr<Sprite> ground = std::make_shared<Sprite>("ground.png", 640, 360);
};
