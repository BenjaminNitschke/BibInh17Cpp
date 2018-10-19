#include <memory>
#include "stdafx.h"
#include "SpaceInvaders.h"
#include "GLFW/glfw3.h"
#include "SpaceInvadersGame.h"
#include "Texture.h"
#include "Sprite.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	auto game = std::make_shared<SpaceInvadersGame>(1280, 720, "Space Invaders");
	auto background = std::make_shared<Sprite>(std::make_shared<Texture>("background.png"), 1280/2, 720/2);
	auto ship = std::make_shared<Sprite>(std::make_shared<Texture>("ship.png"), 1280/2, 720*0.9);
	game->Run([=]()
	{
		background->Draw();
		ship->Draw();
	});
	return 0;
}
