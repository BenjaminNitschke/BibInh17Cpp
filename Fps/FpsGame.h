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
	float Xrotation = 0;
	float Yrotation = 0;
	Vector3 movement = Vector3(0, 0, 0);
	float MovementSpeed = 10.0f;
	float RotationSpeed = 0.3f;
	float DegreeToRadians = (1.0f / 180.0f) * 3.14159f;
	void SetupProjection();
	void UpdateCamera();
	void CalculateMovement(float angle);
	void Input();

public:
	FpsGame() : Game("Fps")
	{
		groundTexture = std::make_shared<Texture>("Ground.png");
		int levelWidth = 20;
		int levelHeight = 20;
		groundVertices.push_back(VertexPositionUV(levelWidth, levelHeight, 0, levelWidth/2, levelHeight/2));
		groundVertices.push_back(VertexPositionUV(-levelWidth, levelHeight, 0, 0, levelHeight/2));
		groundVertices.push_back(VertexPositionUV(-levelWidth, -levelHeight, 0, 0, 0));
		groundVertices.push_back(VertexPositionUV(levelWidth, -levelHeight, 0, levelWidth/2, 0));

		wallTexture = std::make_shared<Texture>("Wall.png");
		AddBox(0, 0);
		AddBox(2, 1);

		SetupProjection();
		glEnable(GL_TEXTURE_2D);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	}
	~FpsGame()
	{
	}
	void RunGame();
	void DrawVertices(std::shared_ptr<Texture> texture, std::vector<VertexPositionUV> vertices);
	void AddBox(int x, int y)
	{
		int size = 4;
		int x0 = x*size;
		int x1 = (x+1)*size;
		int y0 = y*size;
		int y1 = (y+1)*size;
		int z0 = 0;
		int z1 = size;
		wallVertices.push_back(VertexPositionUV(x1, y0, z1, 1, 1));
		wallVertices.push_back(VertexPositionUV(x0, y0, z1, 0, 1));
		wallVertices.push_back(VertexPositionUV(x0, y0, z0, 0, 0));
		wallVertices.push_back(VertexPositionUV(x1, y0, z0, 1, 0));
		wallVertices.push_back(VertexPositionUV(x0, y0, z1, 1, 1));
		wallVertices.push_back(VertexPositionUV(x0, y1, z1, 0, 1));
		wallVertices.push_back(VertexPositionUV(x0, y1, z0, 0, 0));
		wallVertices.push_back(VertexPositionUV(x0, y0, z0, 1, 0));
		wallVertices.push_back(VertexPositionUV(x1, y1, z1, 1, 1));
		wallVertices.push_back(VertexPositionUV(x0, y1, z1, 0, 1));
		wallVertices.push_back(VertexPositionUV(x0, y1, z0, 0, 0));
		wallVertices.push_back(VertexPositionUV(x1, y1, z0, 1, 0));
		wallVertices.push_back(VertexPositionUV(x1, y0, z1, 1, 1));
		wallVertices.push_back(VertexPositionUV(x1, y1, z1, 0, 1));
		wallVertices.push_back(VertexPositionUV(x1, y1, z0, 0, 0));
		wallVertices.push_back(VertexPositionUV(x1, y0, z0, 1, 0));
	}
};

