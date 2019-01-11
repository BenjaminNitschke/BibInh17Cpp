// 2048Ole.cpp : Definiert den Einstiegspunkt für die Anwendung.
//

#include <vector>
#include <memory>
#include "stdafx.h"
#include "2048Ole.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	std::vector<std::shared_ptr<Sprite>> enemyarray;
	std::vector<std::shared_ptr<Sprite>> shootarray;
	auto game = std::make_shared<SpaceInvadersGame>(1280, 720, "Space Invaders");
	auto background = std::make_shared<Sprite>(std::make_shared<Texture>("background.png"), 1280 / 2, 720 / 2);
	auto ship = std::make_shared<Sprite>(std::make_shared<Texture>("ship.png"), 1280 / 2, 720 * 0.9);
	auto shot = std::make_shared<Sprite>(std::make_shared<Texture>("laser.png"), 1280 / 2, 720 * 0.9);
	double b = 0;
	int press = 0;
	bool check = false;
	auto enemy = std::make_shared<Sprite>(std::make_shared<Texture>("enemy.png"), 1280/2, 720 * 0.1);
	for (int i = 0; i < 20; i++)
	{
		b += 200;
		if (i < 10)
		{
			enemyarray.push_back(std::make_shared<Sprite>(std::make_shared<Texture>("enemy.png"), b, 720 * 0.1));
		}
		enemyarray.push_back(std::make_shared<Sprite>(std::make_shared<Texture>("enemy.png"), b, 720 * 0.3));
	}
	for (int i = 0; i < 20; i++)
	{
		shootarray.push_back(std::make_shared<Sprite>(std::make_shared<Texture>("laser.png"), 1280 / 2, 720 * 0.9));
	}
	game->Run([=, &press, &check]()
	{
		background->Draw();
		ship->Draw();
		if (Game::rightPressed)
			ship->Move(10, 0);
		if (Game::leftPressed)
			ship->Move(-10, 0);
		if (Game::shootPressed)
		{
			press += 1;
		}
		for (int i = 0; i < press; i++)
		{
			if (press <= shootarray.size())
			{
				shootarray.at(i)->Draw();
			}
			shootarray.at(i)->Move(0, -5);
		}
		for (int i = 0; i < 20; i++)
		{
			enemyarray.at(i)->Draw();
		}
		if (check == true)
		{
			for (int i = 0; i < 20; i++)
			{
				enemyarray.at(i)->Move(-10, 0);
			}
			check = false;
		}

		if (check == false)
		{
			for (int i = 0; i < 20; i++)
			{
				enemyarray.at(i)->Move(10, 0);
			}
			check = true;
		}
	});
	return 0;
}
