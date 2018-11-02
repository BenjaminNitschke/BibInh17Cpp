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
	static bool leftPressed;
	static bool rightPressed;
	static bool spacePressed;
};