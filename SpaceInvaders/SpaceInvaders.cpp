#include "stdafx.h"
#include "SpaceInvaders.h"
#include "SpaceInvadersGame.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
										 _In_opt_ HINSTANCE hPrevInstance,
										 _In_ LPWSTR    lpCmdLine,
										 _In_ int       nCmdShow)
{
	auto game = new SpaceInvadersGame();
	game->Run([]()
	{
		glBegin(GL_QUADS);
		//create full quad on screen with 4 colors
		glColor3f(1, 0, 0);
		glVertex2f(-1.0f, 1.0f);
		glColor3f(0, 1, 0);
		glVertex2f(1.0f, 1.0f);
		glColor3f(0, 0, 1);
		glVertex2f(1.0, -1.0f);
		glColor3f(1, 1, 0);
		glVertex2f(-1.0f, -1.0f);
		glEnd();
	});
	delete game;
	return 0;
}