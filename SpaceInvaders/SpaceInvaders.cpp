#include "stdafx.h"
#include "SpaceInvaders.h"
#include "SpaceInvadersGame.h"
#include "png.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	auto game = new SpaceInvadersGame();
	game->Run([]()
	{
		glBegin(GL_TRIANGLES);
		glColor3f(1, 0, 0);
		glVertex2f(-1, 1);

		glColor3f(0, 1, 0);
		glVertex2f(1, 1);

		glColor3f(0, 0, 1);
		glVertex2f(-1, -1);
		glEnd();
		
		glBegin(GL_TRIANGLES);
		glColor3f(1, 1, 0);
		glVertex2f(1, -1);

		glColor3f(0, 1, 0);
		glVertex2f(1, 1);

		glColor3f(0, 0, 1);
		glVertex2f(-1, -1);
		glEnd();
	});
	delete game;
	return 0;
}