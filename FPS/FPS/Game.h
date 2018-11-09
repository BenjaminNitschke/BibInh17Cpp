#pragma once
#include <GLFW/glfw3.h>
#include <functional>

class Game
{
public:
	Game(int width, int height, const char* name);
	~Game();
	void Run(std::function<void()> renderFunc);
	GLFWwindow* pWindow;
};
