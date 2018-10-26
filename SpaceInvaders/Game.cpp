﻿#include "stdafx.h"
#include "Game.h"

bool Game::leftPressed;
bool Game::rightPressed;

void OnKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_LEFT)
		Game::leftPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_RIGHT)
		Game::rightPressed = action != GLFW_RELEASE;
}

Game::Game() 
{
	glfwInit();
	window = glfwCreateWindow(1280, 720, "SpaceInvaders", NULL, NULL);
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
		renderFunction();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
