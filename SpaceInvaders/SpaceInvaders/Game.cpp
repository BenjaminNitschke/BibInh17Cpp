#include "stdafx.h"
#include "Game.h"


Game::Game(int width, int height, const char* name) 
{
	glfwInit();
	pWindow = glfwCreateWindow(width, height, name, nullptr, nullptr);
	glfwMakeContextCurrent(pWindow);
}

Game::~Game() 
{
	glfwTerminate();
}

void Game::Run(std::function<void()> renderFunction)
{
	int viewportWidth;
	int viewportHeight;
	while (!glfwWindowShouldClose(pWindow))
	{
		glfwGetWindowSize(pWindow, &viewportWidth, &viewportHeight);
		glViewport(0, 0, viewportWidth, viewportHeight);
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		renderFunction();
		glfwSwapBuffers(pWindow);
		glfwPollEvents();
	}
}