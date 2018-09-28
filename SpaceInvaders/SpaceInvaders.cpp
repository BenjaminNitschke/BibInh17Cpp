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
	game->Run([=]()
	{
		glBindTexture(GL_TEXTURE_2D, game->background);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glVertex2f(-1, 1);

		glTexCoord2f(1, 1);
		glVertex2f(1, 1);

		glTexCoord2f(1, 0);
		glVertex2f(1, -1);

		glTexCoord2f(0, 0);
		glVertex2f(-1, -1);

		glEnd();


		glBindTexture(GL_TEXTURE_2D, game->test);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glVertex2f(-1, 1);

		glTexCoord2f(1, 1);
		glVertex2f(1, 1);

		glTexCoord2f(1, 0);
		glVertex2f(1, -1);

		glTexCoord2f(0, 0);
		glVertex2f(-1, -1);

		glEnd();
	});
	delete game;
	return 0;
}