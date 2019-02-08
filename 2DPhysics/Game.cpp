#include "stdafx.h"
#include "Game.h"



bool Game::leftPressed;
bool Game::rightPressed;
bool Game::spacePressed;



Game::Game()
{
	glfwInit();
	window = glfwCreateWindow(720, 720, "Physictest", NULL, NULL);
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
		time = glfwGetTime();
		timeThisTick = time - lastTime;
		lastTime = time;
		
		renderFunction();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
