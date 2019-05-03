#pragma once
#include <Shader.h>
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
	std::shared_ptr<Shader> groundShader;
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
		float levelWidth = 20;
		float levelHeight = 20;
		groundVertices.push_back(VertexPositionUV(levelWidth, levelHeight, 0.0f, levelWidth/2, levelHeight/2));
		groundVertices.push_back(VertexPositionUV(-levelWidth, levelHeight, 0.0f, 0.0f, levelHeight/2));
		groundVertices.push_back(VertexPositionUV(-levelWidth, -levelHeight, 0.0f, 0.0f, 0.0f));
		groundVertices.push_back(VertexPositionUV(levelWidth, -levelHeight, 0.0f, levelWidth/2, 0.0f));

		wallTexture = std::make_shared<Texture>("Wall.png");
		AddBox(0, 0);
		AddBox(2, 1);

		//Load shaders
		groundShader = std::make_shared<Shader>(
			// Vertex shader
"void main()"
"{"
"  gl_Position.xyz = gl_Position.xyz;"
"  gl_Position.w = 1.0;"
"}",
			// Fragment/Pixel shader
"out vec3 color;"
"void main()"
"{"
"  color = vec3(1.0, 0.0, 0.0);"
"}");

		SetupProjection();
		glEnable(GL_TEXTURE_2D);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	}
	~FpsGame()
	{
	}
	void RunGame();
	void DrawCrosshair();
	void DrawVertices(std::shared_ptr<Texture> texture, std::vector<VertexPositionUV> vertices);
	void AddBox(int x, int y)
	{
		int size = 4;
#pragma warning(disable: 4244)
		float x0 = x*size;
		float x1 = (x+1)*size;
		float y0 = y*size;
		float y1 = (y+1)*size;
		float z0 = 0;
		float z1 = size;
		wallVertices.push_back(VertexPositionUV(x1, y0, z1, 1.0f, 1.0f));
		wallVertices.push_back(VertexPositionUV(x0, y0, z1, 0.0f, 1.0f));
		wallVertices.push_back(VertexPositionUV(x0, y0, z0, 0.0f, 0.0f));
		wallVertices.push_back(VertexPositionUV(x1, y0, z0, 1.0f, 0.0f));

		wallVertices.push_back(VertexPositionUV(x0, y0, z1, 1.0f, 1.0f));
		wallVertices.push_back(VertexPositionUV(x0, y1, z1, 0.0f, 1.0f));
		wallVertices.push_back(VertexPositionUV(x0, y1, z0, 0.0f, 0.0f));
		wallVertices.push_back(VertexPositionUV(x0, y0, z0, 1.0f, 0.0f));

		wallVertices.push_back(VertexPositionUV(x1, y1, z1, 1.0f, 1.0f));
		wallVertices.push_back(VertexPositionUV(x0, y1, z1, 0.0f, 1.0f));
		wallVertices.push_back(VertexPositionUV(x0, y1, z0, 0.0f, 0.0f));
		wallVertices.push_back(VertexPositionUV(x1, y1, z0, 1.0f, 0.0f));

		wallVertices.push_back(VertexPositionUV(x1, y0, z1, 1.0f, 1.0f));
		wallVertices.push_back(VertexPositionUV(x1, y1, z1, 0.0f, 1.0f));
		wallVertices.push_back(VertexPositionUV(x1, y1, z0, 0.0f, 0.0f));
		wallVertices.push_back(VertexPositionUV(x1, y0, z0, 1.0f, 0.0f));
	}
};

