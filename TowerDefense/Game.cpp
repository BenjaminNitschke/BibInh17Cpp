#include "stdafx.h"
#include "Game.h"

bool Game::leftPressed = false;
bool Game::rightPressed = false;
bool Game::spacePressed = false;
double Game::mouseX = 0;
double Game::mouseY = 0;
bool Game::leftMousePressed = false;
bool Game::iPressed = true;

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
	if (key == GLFW_KEY_I)
		Game::iPressed = action != GLFW_RELEASE;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		Game::leftMousePressed = true;
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		Game::leftMousePressed = false;
	}
}

Game::Game() 
{
	glfwInit();
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	window = glfwCreateWindow(1280, 720, "TowerDefense", NULL, NULL);
	auto glfwWindow = (GLFWwindow*)window;
	glfwMakeContextCurrent(glfwWindow);
	glfwSetKeyCallback(glfwWindow, OnKeyboard);
	glfwSetMouseButtonCallback(glfwWindow, mouse_button_callback);
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
