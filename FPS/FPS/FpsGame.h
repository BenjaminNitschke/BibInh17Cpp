#pragma once
#include "Shader.h"
#include "Game.h"
#include <memory>
#include "Sprite.h"
#include "Vector3.h"
#include "VertexPositionUV.h"
#include <vector>
#include "Matrix.h"

class FpsGame : public Game
{
public:
	FpsGame(int width, int height, const char* name);
	void AddBox(int x, int y);
	void AddQuad(std::vector<VertexPositionUV>* cache, float x, float y, float z, float width, float depth, int resolution = 1);
	~FpsGame();
	float Xrotation = 0;
	float Yrotation = 0;
	Vector3 movement = Vector3(0, 0, 0);
	float MovementSpeed = 10.0f;
	float RotationSpeed = 0.1f;
	void RunGame();
	void DrawVertices(std::vector<VertexPositionUV> vertices, std::shared_ptr<Shader> shader,
	                  std::shared_ptr<Texture> diffuse, std::shared_ptr<Texture> normalMap = nullptr);
	void SetupProjection() const;
	void UpdateCamera() const;
	void CalculateMovement(float angle);
	void Input();
	const float DegreeToRadians = (1.0f / 180.0f) * 3.14159f;

	std::vector<VertexPositionUV> groundVertices = std::vector<VertexPositionUV>();
	std::vector<VertexPositionUV> wallVertices = std::vector<VertexPositionUV>();

	std::shared_ptr<Shader> waveAndBlur;
	std::shared_ptr<Shader> normal;
	std::shared_ptr<Shader> texture;

	Vector3 lightDirection = Vector3(-0.707f, 0, 0.707f);

	std::shared_ptr<Sprite> ground = std::make_shared<Sprite>("ground.png", 640, 360);
	std::shared_ptr<Sprite> wall = std::make_shared<Sprite>("wall.png", 640, 360);
	std::shared_ptr<Sprite> normalMap = std::make_shared<Sprite>("normal.png", 640, 360);

	Matrix projection;
	Matrix view;
};
