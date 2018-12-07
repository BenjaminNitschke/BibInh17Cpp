#include "stdafx.h"
#include "Game.h"
#include <GLFW/glfw3.h>
#include "Sprite.h"

bool Game::leftPressed;
bool Game::rightPressed;
bool Game::spacePressed;
bool Game::wPressed;
bool Game::aPressed;
bool Game::sPressed;
bool Game::dPressed;

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
}

void OnKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_LEFT)
		Game::leftPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_RIGHT)
		Game::rightPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_SPACE)
		Game::spacePressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_W)
		Game::wPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_A)
		Game::aPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_S)
		Game::sPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_D)
		Game::dPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, true);
}

Game::Game(const char* title)
{
	glfwInit();
	window = glfwCreateWindow(1280, 720, title, NULL, NULL);
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
	auto glwWindow = (GLFWwindow*)window;
	while (!glfwWindowShouldClose(glwWindow))
	{
		glfwGetWindowSize(glwWindow, &viewportWidth, &viewportHeight);
		glViewport(0, 0, viewportWidth, viewportHeight);
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		time = glfwGetTime();
		timeThisTick = time - lastTime;
		lastTime = time;
		renderFunction();
		glfwSwapBuffers(glwWindow);
		glfwPollEvents();
	}
}