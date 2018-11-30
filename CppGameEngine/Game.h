#pragma once
#include <GLFW/glfw3.h>
#include <functional>

class Game
{
public:
	Game(int width, int height, const char* name);
	~Game();
	GLFWwindow* pWindow;
protected:
	void Run(std::function<void()> renderFunc) const;
};
