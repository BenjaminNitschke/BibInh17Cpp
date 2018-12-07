#pragma once
#include <GLFW/glfw3.h>
#include <functional>

class Game
{
public:
	Game(int width, int height, const char* name);
	~Game();
	GLFWwindow* pWindow;
	static bool leftPressed;
	static bool upPressed;
	static bool rightPressed;
	static bool downPressed;
	static bool spacePressed;

	static float xDelta;
	static float yDelta;
protected:
	void Run(std::function<void()> renderFunc) const;
};
