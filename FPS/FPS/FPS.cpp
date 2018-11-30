#include "stdafx.h"
#include "FPS.h"
#include "FpsGame.h"
#include <memory>
#include "Sprite.h"

// Main function
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	// Create a bare game
	auto game = std::make_shared<FpsGame>(1280, 720, "First Person Shooter");

	game->RunGame();

	return 0;
}
