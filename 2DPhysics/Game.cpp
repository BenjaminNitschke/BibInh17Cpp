#include "stdafx.h"
#include "Game.h"



bool Game::upPressed;
bool Game::downPressed;
bool Game::leftPressed;
bool Game::rightPressed;

void OnKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_UP)
		Game::upPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_DOWN)
		Game::downPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_LEFT)
		Game::leftPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_RIGHT)
		Game::rightPressed = action != GLFW_RELEASE;
		
}

Game::Game()
{
	glfwInit();
	window = glfwCreateWindow(1440, 1440, "Physictest", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, OnKeyboard);
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
		time = glfwGetTime();
		timeThisTick = time - lastTime;
		lastTime = time;
		
		renderFunction();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
