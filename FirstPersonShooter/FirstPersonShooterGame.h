#pragma once
#include <Game.h>
#include <Texture.h>
#include <memory>
#include <Vector3.h>

class FirstPersonShooterGame : public Game
{
	std::shared_ptr<Texture> groundTexture;
	float rotation = 0;
	Vector3 movement = Vector3(0, 0, 0);
	float DegreeToRadians = (1.0f / 180.0f) * 3.14159f;
	void SetupProjection();
	void UpdateCamera();
	//void glfwGetCursorPos(GLFW* window, double* xPos, double* yPos);
public:
	FirstPersonShooterGame() : Game("FistPersonShooter")
	{
		//Load textures
		groundTexture = std::make_shared<Texture>("ground.png");
		SetupProjection();
		//glfwGetCursorPos();
		UpdateCamera();
	};
	~FirstPersonShooterGame() 
	{
	}
	
	void RunGame();
};