#pragma once
#include <GLFW/glfw3.h>
#include <functional>

class Game
{
public:
	Game(int width, int height, const char* name);
	~Game();
	static GLFWwindow* pWindow;
	int viewportWidth;
	int viewportHeight;
	static bool leftPressed;
	static bool upPressed;
	static bool rightPressed;
	static bool downPressed;
	static bool spacePressed;

	static float xDelta;
	static float yDelta;
	double time = 0;
	double lastTime = 0;
	double timeThisTick = 0.001;
	float GetTimeDelta() { return static_cast<float>(timeThisTick); }
protected:
	void Run(std::function<void()> renderFunc); 
};
