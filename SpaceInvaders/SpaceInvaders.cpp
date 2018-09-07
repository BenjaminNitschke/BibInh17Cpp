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
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}