#include "stdafx.h"
#include "SpaceInvaders.h"
#include "SpaceInvadersGame.h"
#include <memory>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	// an instance of the base game
	const auto game = std::make_shared<SpaceInvadersGame>(1280, 720, "Space Invaders");

	game->RunSpaceInvaders();
}
