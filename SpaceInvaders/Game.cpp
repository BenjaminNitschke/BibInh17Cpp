#include "stdafx.h"
#include "Game.h"
#include <functional>

Game::Game()
{
	glfwInit();
	window = glfwCreateWindow(1280, 720, "SpaceInvaders", NULL, NULL);
	glfwMakeContextCurrent(window);
	// More initialization later here
}

void Game::Run(std::function<void()> renderFunction)
{
	while (!glfwWindowShouldClose(window))
	{
		// glClearColor(0, 1, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		// Game code goes here, plus input handling and timing before that
		renderFunction();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

Game::~Game()
{
	glfwTerminate();
}