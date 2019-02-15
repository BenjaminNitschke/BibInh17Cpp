#include "stdafx.h"
#include "Game.h"
#include <iostream>
using namespace std;

bool Game::leftPressed;
bool Game::rightPressed;
bool Game::upPressed;
bool Game::downPressed;
bool Game::leftJustPressed;
bool Game::rightJustPressed;
bool Game::upJustPressed;
bool Game::downJustPressed;

void OnKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Game::leftJustPressed = (key == GLFW_KEY_LEFT && action != GLFW_RELEASE && !Game::leftPressed && !Game::leftJustPressed);
	if (key == GLFW_KEY_LEFT)
		Game::leftPressed = action != GLFW_RELEASE;
	Game::rightJustPressed = (key == GLFW_KEY_RIGHT && action != GLFW_RELEASE && !Game::rightPressed && !Game::rightJustPressed);
	if (key == GLFW_KEY_RIGHT)
		Game::rightPressed = action != GLFW_RELEASE;
	Game::upJustPressed = (key == GLFW_KEY_UP && action != GLFW_RELEASE && !Game::upPressed && !Game::upJustPressed);
	if (key == GLFW_KEY_UP)
		Game::upPressed = action != GLFW_RELEASE;
	Game::downJustPressed = (key == GLFW_KEY_DOWN && action != GLFW_RELEASE && !Game::downPressed && !Game::downJustPressed);
	if (key == GLFW_KEY_DOWN)
		Game::downPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, true);
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
		time = glfwGetTime();
		timeThisTick = time - lastTime;
		lastTime = time;
		renderFunction();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
