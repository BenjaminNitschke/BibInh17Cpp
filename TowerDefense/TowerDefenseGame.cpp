#include "stdafx.h"
#include "TowerDefenseGame.h"
#include "Sprite.h"
#include <memory>
#include <vector>

TowerDefenseGame::TowerDefenseGame(int width, int height, const char* name)
{
	background = std::make_shared<Sprite>(std::make_shared<Texture>("background.png"), 1280 / 2, 720 / 2);
	slot = std::make_shared<Texture>("slot.png");
	slot_way = std::make_shared<Texture>("slot_way.png");
	slot_grass = std::make_shared<Texture>("slot_grass.png");
	slot_selected = std::make_shared<Sprite>(std::make_shared<Texture>("slot_selected.png"), 1280 / 2, 720 / 2);
	enemy1 = std::make_shared<Texture>("enemy1.png");
	enemy2 = std::make_shared<Texture>("enemy2.png");
	enemy3 = std::make_shared<Texture>("enemy3.png");
	enemies.push_back(*(new Sprite(enemy1, 80 * -1 + 40, 80 * 2 + 40)));
	
	for (int x = 0; x < 16; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if(map[y][x] == 0) slots.push_back(*(new Sprite(slot, x * 80 + 40, y * 80 + 40)));
			else if(map[y][x] == 1) slots.push_back(*(new Sprite(slot_way, x * 80 + 40, y * 80 + 40)));
			else if (map[y][x] == 2) slots.push_back(*(new Sprite(slot_grass, x * 80 + 40, y * 80 + 40)));
		}
	}

	enemyWay.push_back(*(new Point(0, 2)));
	enemyWay.push_back(*(new Point(1, 2)));
	enemyWay.push_back(*(new Point(2, 2)));
	enemyWay.push_back(*(new Point(3, 2)));
	enemyWay.push_back(*(new Point(4, 2)));
	enemyWay.push_back(*(new Point(4, 3)));
	enemyWay.push_back(*(new Point(4, 4)));
	enemyWay.push_back(*(new Point(4, 5)));
	enemyWay.push_back(*(new Point(4, 6)));
	enemyWay.push_back(*(new Point(5, 6)));
	enemyWay.push_back(*(new Point(6, 6)));
	enemyWay.push_back(*(new Point(7, 6)));
	enemyWay.push_back(*(new Point(8, 6)));
	enemyWay.push_back(*(new Point(9, 6)));
	enemyWay.push_back(*(new Point(10, 6)));
	enemyWay.push_back(*(new Point(11, 6)));
	enemyWay.push_back(*(new Point(12, 6)));
	enemyWay.push_back(*(new Point(12, 5)));
	enemyWay.push_back(*(new Point(12, 4)));
	enemyWay.push_back(*(new Point(13, 4)));
	enemyWay.push_back(*(new Point(14, 4)));
	enemyWay.push_back(*(new Point(15, 4)));
}

TowerDefenseGame::~TowerDefenseGame()
{
}

void TowerDefenseGame::RunSpaceInvaders()
{
	lastTime = glfwGetTime();
	Run([=]()
	{
		CalculateSelectedSlot();
		CalculateEnemyMovement();
		DrawAll();
	});
}

void TowerDefenseGame::CalculateSelectedSlot()
{
	slot_selected_x = ((int)mouseX) / 80;
	slot_selected_y = ((int)mouseY) / 80;
	slot_selected->setPos(slot_selected_x * 80 + 40, slot_selected_y * 80 + 40);
}

void TowerDefenseGame::CalculateEnemyMovement()
{
	int index = 0;

	float currentX = enemies[0].getPos(0) / 80;
	float currentY = enemies[0].getPos(1) / 80;

	double now = glfwGetTime();
	double delta = now - lastTime;
	lastTime = now;

	if (std::abs(enemies[0].getPos(0) - enemyWay[index].x) < 5 && std::abs(enemies[0].getPos(1) - enemyWay[index].y) < 5)
	{
		index++;
	}

	enemies[0].setPos(enemyWay[index].x * 80 + 40 + delta, enemyWay[index].y * 80 + 40 + delta);
}

void TowerDefenseGame::DrawAll()
{
	background->Draw();
	for (int i = 0; i < slots.size(); i++)
	{
		Sprite *tmp = &slots.at(i);
		tmp->Draw();
	}
	slot_selected->Draw();

	for (int i = 0; i < enemies.size(); i++)
	{
		Sprite *tmp = &enemies.at(i);
		tmp->Draw();
	}
}

double TowerDefenseGame::DistanceTo(Sprite* missile, Sprite* enemie)
{
	double x = missile->getPos(0) - enemie->getPos(0);
	double y = missile->getPos(1) - enemie->getPos(1);
	return sqrt((x*x) + (y*y));
}