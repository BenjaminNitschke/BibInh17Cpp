#pragma once
#include <GLFW/glfw3.h>
#include <functional>

class Game
{
public:
	Game();
	~Game();
	//void OnKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods);
	void Run(std::function<void()> renderFunc);
	static bool leftPressed;
	static bool rightPressed;
private:
	GLFWwindow* window;
};
