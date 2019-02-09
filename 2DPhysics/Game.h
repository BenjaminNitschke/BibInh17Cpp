#pragma once
#include <GLFW/glfw3.h>
#include <functional>

class Game
{
private:
	GLFWwindow * window;
public:
	Game();
	~Game();
	void Run(std::function<void()> renderFunction);
	static bool upPressed;
	static bool downPressed;
	static bool spacePressed;
	double time = 0;
	double lastTime = 0;
	double timeThisTick = 0.001;
	float GetTimeDelta() { return static_cast<float>(timeThisTick); }
};
