#pragma once
#include <Game.h>
#include <Texture.h>
#include <memory>
#include <Vector3.h>
#include <vector>
#include <VertexPositionUV.h>

class FpsGame : public Game
{
	std::vector<VertexPositionUV> groundVertices = std::vector<VertexPositionUV>(); 
	std::vector<VertexPositionUV> wallVertices = std::vector<VertexPositionUV>(); 
	std::shared_ptr<Texture> groundTexture;
	std::shared_ptr<Texture> wallTexture;
	float rotation = 0;
	Vector3 movement = Vector3(0, 0, 0);
	float DegreeToRadians = (1.0f / 180.0f) * 3.14159f;
	void SetupProjection();
	void UpdateCamera();

public:
	FpsGame() : Game("Fps")
	{
		groundTexture = std::make_shared<Texture>("Ground.png");
		int levelWidth = 10;
		int levelHeight = 10;
		groundVertices.push_back(VertexPositionUV(levelWidth, levelHeight, 0, levelWidth/2, levelHeight/2));
		groundVertices.push_back(VertexPositionUV(-levelWidth, levelHeight, 0, 0, levelHeight/2));
		groundVertices.push_back(VertexPositionUV(-levelWidth, -levelHeight, 0, 0, 0));
		groundVertices.push_back(VertexPositionUV(levelWidth, -levelHeight, 0, levelWidth/2, 0));

		wallTexture = std::make_shared<Texture>("Wall.png");
		//TODO: make function for this
		wallVertices.push_back(VertexPositionUV(2, 0, 4, 1, 1));
		wallVertices.push_back(VertexPositionUV(-2, 0, 4, 0, 1));
		wallVertices.push_back(VertexPositionUV(-2, 0, 0, 0, 0));
		wallVertices.push_back(VertexPositionUV(2, 0, 0, 1, 0));
		//TODO: add 2 more walls and rotate (X, Y)
		wallVertices.push_back(VertexPositionUV(2, 1, 4, 1, 1));
		wallVertices.push_back(VertexPositionUV(-2, 1, 4, 0, 1));
		wallVertices.push_back(VertexPositionUV(-2, 1, 0, 0, 0));
		wallVertices.push_back(VertexPositionUV(2, 1, 0, 1, 0));
		wallVertices.push_back(VertexPositionUV(2, 2, 4, 1, 1));
		wallVertices.push_back(VertexPositionUV(-2, 2, 4, 0, 1));
		wallVertices.push_back(VertexPositionUV(-2, 2, 0, 0, 0));
		wallVertices.push_back(VertexPositionUV(2, 2, 0, 1, 0));

		SetupProjection();
		glEnable(GL_TEXTURE_2D);
	}
	~FpsGame()
	{
	}
	void RunGame();
	void DrawVertices(std::shared_ptr<Texture> texture, std::vector<VertexPositionUV> vertices);
};

