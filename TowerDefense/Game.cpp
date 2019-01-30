#include "stdafx.h"
#include "Game.h"

bool Game::leftPressed = false;
bool Game::rightPressed = false;
bool Game::spacePressed = false;
double Game::mouseX = 0;
double Game::mouseY = 0;

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Game::mouseX = xpos;
	Game::mouseY = ypos;
}

void OnKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_LEFT)
		Game::leftPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_RIGHT)
		Game::rightPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_SPACE)
		Game::spacePressed = action != GLFW_RELEASE;
}

Game::Game() 
{
	glfwInit();
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	window = glfwCreateWindow(1280, 720, "TowerDefense", NULL, NULL);
	auto glfwWindow = (GLFWwindow*)window;
	glfwMakeContextCurrent(glfwWindow);
	glfwSetKeyCallback(glfwWindow, OnKeyboard);
	glfwSetCursorPosCallback(glfwWindow, cursor_position_callback);
}

Game::~Game() 
{
	glfwTerminate();
}

void Game::Run(std::function<void()> renderFunction)
{
	int viewportWidth;
	int viewportHeight;

	while (!glfwWindowShouldClose(window))
	{
		glfwGetWindowSize(window, &viewportWidth, &viewportHeight);
		glViewport(0, 0, viewportWidth, viewportHeight);
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		renderFunction();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
