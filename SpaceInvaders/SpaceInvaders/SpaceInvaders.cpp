#include "stdafx.h"
#include "SpaceInvaders.h"
#include "GLFW/glfw3.h"
#include "SpaceInvadersGame.h"
#include "Texture.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	auto game = new SpaceInvadersGame(1280, 720, "Space Invaders");
	auto image = new Texture("background.png");		
	auto bg = new Texture("test.png");
	game->Run([image, bg]()
	{
		image->Draw();
		bg->Draw();
	});
	delete game;
	return 0;
}
