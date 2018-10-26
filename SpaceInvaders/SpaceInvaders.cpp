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
	auto background = std::make_shared<Sprite>(std::make_shared<Texture>("background.png"), 1280/2, 720/2);
	auto ship = std::make_shared<Sprite>(std::make_shared<Texture>("ship.png"), 1280/2, 720*0.9);
	auto enemyTexture = std::make_shared<Texture>("enemy.png");
	auto enemies = std::vector<std::shared_ptr<Sprite>>();
	enemies.push_back(std::make_shared<Sprite>(enemyTexture, 720, 83));
	//TODO: enemyTexture and 20 * enemies in 2 rows
	game->Run([=]()
	{
		//TODO later: handle input, control player ship
		//TODO later: handle enemy ai, move enemies
		background->Draw();
		ship->Draw();
		enemies[0]->Draw();
		//TODO: draw enemies
	});
	return 0;
}
