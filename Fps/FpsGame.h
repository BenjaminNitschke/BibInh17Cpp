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
		float rotation = 0;
		Vector3 movement = Vector3(0, 0, 0);
	public:
		FpsGame() : Game("Fps")
		{
			// Load Textures
			groundTexture = std::make_shared<Texture>("ground.png");
		};
		void RunGame();
	};
}