#include "stdafx.h"
#include "Game.h"

Game::Game() 
{
	glfwInit();
	window = glfwCreateWindow(1280, 720, "SpaceInvaders", NULL, NULL);
	glfwMakeContextCurrent(window);
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
