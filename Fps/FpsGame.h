#pragma once
#include "Game.h"
#include "Texture.h"
#include "Sprite.h"
#include "Vector3.h"
#include <memory>
namespace Fps
{
	class FpsGame : public Game
	{
		std::shared_ptr<Texture> groundTexture;
		float rotationX = 270;
		float rotationY = -110;
		Vector3 movement = Vector3(0, 0, 0);
		const float degreeToRadian = 3.14159f / 180;
		float movementSpeed = 0.1f;
	public:
		FpsGame() : Game("Fps")
		{
			// Load Textures
			groundTexture = std::make_shared<Texture>("ground.png");
			SetupProjection();
		};
		void RunGame();
		void SetupProjection();
		void UpdateCamera();
	};
}