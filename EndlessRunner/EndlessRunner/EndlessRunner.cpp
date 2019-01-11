
#include "stdafx.h"
#include <memory>
#include <vector>
#include "EndlessRunner.h"
#include "GLFW/glfw3.h"
#include "EndlessRunnerGame.h"
#include "Texture.h"
#include "Sprite.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	auto game = std::make_shared<EndlessRunnerGame>(1920, 1080, "Space Invaders");
	game->RunEndlessRunner();
	return 0;
}
