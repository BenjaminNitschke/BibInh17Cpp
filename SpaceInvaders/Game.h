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
};