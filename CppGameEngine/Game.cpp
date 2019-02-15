#include "stdafx.h"
#include "Game.h"
#include <GLFW/glfw3.h>

bool Game::leftPressed;
bool Game::upPressed;
bool Game::rightPressed;
bool Game::downPressed;
bool Game::spacePressed;
bool Game::leftMouseButtonClicked;
float Game::xDelta;
float Game::yDelta;
double Game::posX;
double Game::posY;

void OnKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_A)
		Game::leftPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_W)
		Game::upPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_D || key == GLFW_KEY_E)
		Game::rightPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_S || key == GLFW_KEY_O)
		Game::downPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_SPACE)
		Game::spacePressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, true);
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		Game::leftMouseButtonClicked = true;
	}
	else	Game::leftMouseButtonClicked = false;
		
}
//float oldPosX, oldPosY;
//void OnMouse(GLFWwindow* window, double posX, double posY)
//{
//	Game::xDelta = oldPosX - posX;
//	Game::yDelta = oldPosY - posY;
//	oldPosX = posX;
//	oldPosY = posY;
//}

void OnMouse(GLFWwindow* window, double posX, double posY)
{
	Game::posX = posX;
	Game::posY = posY;
}

Game::Game(const char* title)
{
	glfwInit();
	window = glfwCreateWindow(1280, 720, title, NULL, NULL);
	auto glfwWindow = (GLFWwindow*)window;
	glfwMakeContextCurrent(glfwWindow);
	//glfwSetInputMode(glfwWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetKeyCallback(glfwWindow, OnKeyboard);
	glfwSetCursorPosCallback(glfwWindow, OnMouse);
	glfwGetWindowSize(glfwWindow, &viewportWidth, &viewportHeight);
	glEnable(GL_DEPTH_TEST);
	glfwSetMouseButtonCallback((GLFWwindow*)window, mouse_button_callback);
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

