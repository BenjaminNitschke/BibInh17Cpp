#include "stdafx.h"
#include "SpaceInvaders.h"
#include "GLFW/glfw3.h"
#include "SpaceInvadersGame.h"
#include "Texture.h"
#include "Sprite.h"
#include <memory>
#include <vector>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	auto game = std::make_shared<SpaceInvadersGame>(1280, 720, "Space Invaders");
	auto background = std::make_shared<Sprite>(std::make_shared<Texture>("background.png"), 1280/2, 720/2);
	auto ship = std::make_shared<Sprite>(std::make_shared<Texture>("ship.png"), 1280/2, 720*0.9);
	//auto alien_ship = std::make_shared<Texture>("alien_ship.png");
	std::vector<std::shared_ptr<Sprite>> enemy;
	
	for (int i = 0; i < 10; i++)
	{
		enemy.push_back(std::make_shared<Sprite>(std::make_shared<Texture>("alien_ship"), (1280 / 10) * i, 720 * 0.5));
	}
	
	game->Run([=]()
	{
		background->Draw();
		ship->Draw();
		//alien_ship->Draw();
		for (int i = 0; i < enemy.size(); i++)
		{
			enemy.at(i)->Draw();
		}
		
	});
	return 0;
}
