#include "stdafx.h"
#include "Game.h"
#include <GLFW/glfw3.h>

bool Game::leftPressed;
bool Game::rightPressed;
bool Game::upPressed;
bool Game::downPressed;
bool Game::turnLeftPressed;
bool Game::turnRightPressed;
bool Game::spacePressed;

void OnKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_A)
		Game::leftPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_D)
		Game::rightPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_W)
		Game::upPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_S)
		Game::downPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_Q)
		Game::turnLeftPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_E)
		Game::turnRightPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_SPACE)
		Game::spacePressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, true);
}

Game::Game(const char* title)
{
	glfwInit();
	window = glfwCreateWindow(1280, 720, title, NULL, NULL);
	auto glwWindow = (GLFWwindow*)window;
	glfwMakeContextCurrent(glwWindow);
	glfwSetKeyCallback(glwWindow, OnKeyboard);
	glEnable(GL_DEPTH_TEST);
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
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		time = glfwGetTime();
		timeThisTick = time - lastTime;
		lastTime = time;
		renderFunction();
		glfwSwapBuffers(glwWindow);
		glfwPollEvents();
	}
}

void Game::RunTriangle()
{
	Run([=]()
	{
		glBegin(GL_TRIANGLES);
		glColor3f(1.f, 0.f, 0.f);
		glVertex3f(-0.6f, -0.4f, 0.f);
		glColor3f(0.f, 1.f, 0.f);
		glVertex3f(0.6f, -0.4f, 0.f);
		glColor3f(0.f, 0.f, 1.f);
		glVertex3f(0.f, 0.6f, 0.f);
		glEnd();
	});
}