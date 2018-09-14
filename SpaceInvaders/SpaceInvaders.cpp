#include "stdafx.h"
#include "SpaceInvaders.h"
#include <GLFW/glfw3.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
										 _In_opt_ HINSTANCE hPrevInstance,
										 _In_ LPWSTR    lpCmdLine,
										 _In_ int       nCmdShow)
{
	glfwInit();
	auto window = glfwCreateWindow(1280, 720, "SpaceInvaders", NULL, NULL);
	glfwMakeContextCurrent(window);
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0, 1, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}