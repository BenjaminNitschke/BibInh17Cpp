﻿#include "stdafx.h"
#include "Game.h"

// Create a new Game-instance
Game::Game(int width, int height, const char* name)
{
	// start GLFW
	glfwInit();
	// create a window
	pWindow = glfwCreateWindow(width, height, name, nullptr, nullptr);
	// tell glfw it should use the created window
	glfwMakeContextCurrent(pWindow);
}

Game::~Game() 
{
	// stop glfw
	glfwTerminate();
}

// game loop
void Game::Run(std::function<void()> renderFunction)
{
	// width and height of the window
	int viewportWidth;
	int viewportHeight;
	// while the window is open
	while (!glfwWindowShouldClose(pWindow))
	{
		// get the size of the window to support resizing
		glfwGetWindowSize(pWindow, &viewportWidth, &viewportHeight);
		// set the viewport
		glViewport(0, 0, viewportWidth, viewportHeight);
		// clear the screen
		glClearColor(0, 0, 0, 1);
		// clear the buffer
		glClear(GL_COLOR_BUFFER_BIT);
		// execute rendering
		renderFunction();
		// bring rendered things on the screen
		glfwSwapBuffers(pWindow);
		// check if something happened to the window
		glfwPollEvents();
	}
}