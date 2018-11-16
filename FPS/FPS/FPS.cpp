#include "stdafx.h"
#include "FPS.h"
#include "Game.h"
#include <memory>

// Main function
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	// Create a bare game
	auto game = std::make_shared<Game>(1280, 720, "First Person Shooter");

	return 0;
}

