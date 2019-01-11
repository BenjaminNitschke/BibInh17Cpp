#include "stdafx.h"
#include "Game.h"
#include <GLFW/glfw3.h>

bool Game::aPressed;
bool Game::dPressed;
bool Game::wPressed;
bool Game::sPressed;

void OnKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_A)
		Game::aPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_D)
		Game::dPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_W)
		Game::wPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_S)
		Game::sPressed = action != GLFW_RELEASE;
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
	glfwGetWindowSize(glfwWindow, &viewportWidth, &viewportHeight);
	glEnable(GL_DEPTH_TEST);
}

Game::~Game() 
{
	glfwTerminate();
}

void Game::Run(std::function<void()> renderFunction)
{
	auto glfwWindow = (GLFWwindow*)window;
	while (!glfwWindowShouldClose(glfwWindow))
	{
		glfwGetWindowSize(glfwWindow, &viewportWidth, &viewportHeight);
		glViewport(0, 0, viewportWidth, viewportHeight);
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		time = glfwGetTime();
		timeThisTick = time - lastTime;
		lastTime = time;
		renderFunction();
		glfwSwapBuffers(glfwWindow);
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
