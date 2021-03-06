#include "stdafx.h"
#include <memory>
#include <vector>
#include "SpaceInvaders.h"
#include "GLFW/glfw3.h"
#include "SpaceInvadersGame.h"
#include "Texture.h"
#include "Sprite.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	auto game = std::make_shared<SpaceInvadersGame>(1280, 720, "Space Invaders");
	game->RunSpaceInvaders();
	return 0;
}
