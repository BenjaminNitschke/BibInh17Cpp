#pragma once
#include "Game.h"
#include "Texture.h"
#include "Sprite.h"
#include "Vector3.h"
#include <memory>
#include <vector>
#include "VertexPositionUV.h"

namespace Fps
{
	class FpsGame : public Game
	{
		std::vector<VertexPositionUV> groundVertices;
		std::shared_ptr<Texture> groundTexture;
		std::vector<VertexPositionUV> wallVertices;
		std::shared_ptr<Texture> wallTexture;
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
			int levelWidth = 20;
			int levelHeight = 20;
			groundVertices.push_back(VertexPositionUV(levelWidth, levelHeight, 0, levelWidth/2, levelHeight/2));
			groundVertices.push_back(VertexPositionUV(-levelWidth, levelHeight, 0, 0, levelHeight/2));
			groundVertices.push_back(VertexPositionUV(-levelWidth, -levelHeight, 0, 0, 0));
			groundVertices.push_back(VertexPositionUV(levelWidth, -levelHeight, 0, levelWidth/2, 0));

			wallTexture = std::make_shared<Texture>("wall.png");

			for (int i = -4; i < 6; i++)
			{
				wallVertices.push_back(VertexPositionUV((i * 4), 20, 4, 1, 1));
				wallVertices.push_back(VertexPositionUV((i * 4) - 4, 20, 4, 0, 1));
				wallVertices.push_back(VertexPositionUV((i * 4) - 4, 20, 0, 0, 0));
				wallVertices.push_back(VertexPositionUV((i * 4), 20, 0, 1, 0));
			}

			for (int i = -4; i < 6; i++)
			{
				wallVertices.push_back(VertexPositionUV((i * 4), -20, 4, 1, 1));
				wallVertices.push_back(VertexPositionUV((i * 4) - 4, -20, 4, 0, 1));
				wallVertices.push_back(VertexPositionUV((i * 4) - 4, -20, 0, 0, 0));
				wallVertices.push_back(VertexPositionUV((i * 4), -20, 0, 1, 0));
			}

			for (int i = -4; i < 6; i++)
			{
				wallVertices.push_back(VertexPositionUV(20, (i * 4), 4, 1, 1));
				wallVertices.push_back(VertexPositionUV(20, (i * 4) - 4, 4, 0, 1));
				wallVertices.push_back(VertexPositionUV(20, (i * 4) - 4, 0, 0, 0));
				wallVertices.push_back(VertexPositionUV(20, (i * 4), 0, 1, 0));
			}

			for (int i = -4; i < 6; i++)
			{
				wallVertices.push_back(VertexPositionUV(-20, (i * 4), 4, 1, 1));
				wallVertices.push_back(VertexPositionUV(-20, (i * 4) - 4, 4, 0, 1));
				wallVertices.push_back(VertexPositionUV(-20, (i * 4) - 4, 0, 0, 0));
				wallVertices.push_back(VertexPositionUV(-20, (i * 4), 0, 1, 0));
			}

			SetupProjection();
			glEnable(GL_TEXTURE_2D);
		};
		void RunGame();
		void SetupProjection();
		void UpdateCamera();
		void DrawVertices(std::shared_ptr<Texture> texture, std::vector<VertexPositionUV> vertices);
	};
}