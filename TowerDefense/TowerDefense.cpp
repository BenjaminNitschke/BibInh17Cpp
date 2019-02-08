#include "stdafx.h"
#include <memory>
#include <vector>
#include "TowerDefense.h"
#include "GLFW/glfw3.h"
#include "TowerDefenseGame.h"
#include "Texture.h"
#include "Sprite.h"

int main()
{
	wWinMain(0, 0, 0, 0);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	auto game = std::make_shared<TowerDefenseGame>(1280, 720, "Tower Defense");

	game->RunSpaceInvaders();
	return 0;
}
