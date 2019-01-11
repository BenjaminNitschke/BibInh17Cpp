#include "stdafx.h"
#include "Game.h"

bool Game::leftPressed;
bool Game::upPressed;
bool Game::rightPressed;
bool Game::downPressed;
bool Game::spacePressed;

float Game::xDelta;
float Game::yDelta;


float oldPosX, oldPosY;

void OnKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_A)
		Game::leftPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_W)
		Game::upPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_D)
		Game::rightPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_S)
		Game::downPressed = action != GLFW_RELEASE;
	if (key == GLFW_KEY_SPACE)
		Game::spacePressed = action != GLFW_RELEASE;

	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, true);
}

void OnMouse(GLFWwindow* window, double posX, double posY)
{
	Game::xDelta = oldPosX - posX;
	Game::yDelta = oldPosY - posY;

	//std::cout << "x: " << Game::xDelta << "\n";
	//std::cout << "y: " << Game::yDelta << "\n";

	//system("cls");

	oldPosX = posX;
	oldPosY = posY;
	//glfwSetCursorPos(window, 1280/2, 720/2);
}

// Create a new Game-instance
Game::Game(int width, int height, const char* name)
{
	// start GLFW
	glfwInit();
	// create a window
	pWindow = glfwCreateWindow(width, height, name, nullptr, nullptr);
	// tell glfw it should use the created window
	glfwMakeContextCurrent(pWindow);
	glfwSetInputMode(pWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetKeyCallback(pWindow, OnKeyboard);
	glfwSetCursorPosCallback(pWindow, OnMouse);
	glEnable(GL_DEPTH_TEST);
}

Game::~Game()
{
	// stop glfw
	glfwTerminate();
}

// game loop
void Game::Run(std::function<void()> renderFunc)
{
	// width and height of the window
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
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		time = glfwGetTime();
		timeThisTick = time - lastTime;
		lastTime = time;
		// execute rendering
		renderFunc();
		// bring rendered things on the screen
		glfwSwapBuffers(pWindow);
		// check if something happened to the window
		glfwPollEvents();
	}
}
