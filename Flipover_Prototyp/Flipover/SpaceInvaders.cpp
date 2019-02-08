#include "stdafx.h"
#include <memory>
#include <vector>
#include "SpaceInvaders.h"
#include "GLFW/glfw3.h"
#include "SpaceInvadersGame.h"
#include "Texture.h"
#include "Sprite.h"
#include <time.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	srand(time(NULL));
	auto game = std::make_shared<FlipoverGame>(1280, 720, "Flipover");
	game->RunFlipover();
	return 0;
}
