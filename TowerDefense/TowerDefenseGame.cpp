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
	slot_towerSelection = std::make_shared<Texture>("slot_towerSelection.png");
	slot_selected = std::make_shared<Sprite>(std::make_shared<Texture>("slot_selected.png"), 80 * -1 + 40, 80 * -1 + 40);
	enemy1 = std::make_shared<Texture>("enemy1.png");
	enemy2 = std::make_shared<Texture>("enemy2.png");
	enemy3 = std::make_shared<Texture>("enemy3.png");
	tower1 = std::make_shared<Texture>("tower1.png");
	tower2 = std::make_shared<Texture>("tower2.png");
	tower3 = std::make_shared<Texture>("tower3.png");
	numbers.push_back(std::make_shared<Texture>("numbers/0.png"));
	numbers.push_back(std::make_shared<Texture>("numbers/1.png"));
	numbers.push_back(std::make_shared<Texture>("numbers/2.png"));
	numbers.push_back(std::make_shared<Texture>("numbers/3.png"));
	numbers.push_back(std::make_shared<Texture>("numbers/4.png"));
	numbers.push_back(std::make_shared<Texture>("numbers/5.png"));
	numbers.push_back(std::make_shared<Texture>("numbers/6.png"));
	numbers.push_back(std::make_shared<Texture>("numbers/7.png"));
	numbers.push_back(std::make_shared<Texture>("numbers/8.png"));
	numbers.push_back(std::make_shared<Texture>("numbers/9.png"));


	towers.push_back(*(new Sprite(tower1, 7 * 80 + 40, 0 * 80 + 40)));
	towers.push_back(*(new Sprite(tower2, 8 * 80 + 40, 0 * 80 + 40)));
	towers.push_back(*(new Sprite(tower3, 9 * 80 + 40, 0 * 80 + 40)));

	numbersDrawn.push_back(*(new Sprite(numbers.at(5), 7 * 80 + 67 - 8 * 0, 0 * 80 + 68)));
	numbersDrawn.push_back(*(new Sprite(numbers.at(1), 8 * 80 + 67 - 8 * 1, 0 * 80 + 68)));
	numbersDrawn.push_back(*(new Sprite(numbers.at(0), 8 * 80 + 67 - 8 * 0, 0 * 80 + 68)));
	numbersDrawn.push_back(*(new Sprite(numbers.at(2), 9 * 80 + 67 - 8 * 1, 0 * 80 + 68)));
	numbersDrawn.push_back(*(new Sprite(numbers.at(0), 9 * 80 + 67 - 8 * 0, 0 * 80 + 68)));

	enemies.push_back(*(new Sprite(enemy1, 80 * -1 + 40, 80 * 2 + 40)));

	for (int x = 0; x < 16; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if(map[y][x] == 0) slots.push_back(*(new Sprite(slot, x * 80 + 40, y * 80 + 40)));
			else if(map[y][x] == 1) slots.push_back(*(new Sprite(slot_way, x * 80 + 40, y * 80 + 40)));
			else if (map[y][x] == 2) slots.push_back(*(new Sprite(slot_grass, x * 80 + 40, y * 80 + 40)));
			else if (map[y][x] == 3) slots.push_back(*(new Sprite(slot_towerSelection, x * 80 + 40, y * 80 + 40)));
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
	enemyWay.push_back(*(new Point(16, 4)));
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
		CalculateMouseInput();
		CalculateEnemyMovement();
		DrawAll();
	});
}

int seletedTowerIndex = -1;
int towerIndex = 0;
bool towerSelected = false;

void TowerDefenseGame::CalculateMouseInput()
{
	if (leftMousePressed)
	{
		slot_selected->setPos(slot_selected_x * 80 + 40, slot_selected_y * 80 + 40);

		if (slot_selected_x == 7 && slot_selected_y == 0)
		{
			seletedTowerIndex = 0;
		}
		else if (slot_selected_x == 8 && slot_selected_y == 0)
		{
			seletedTowerIndex = 1;
		}
		else if (slot_selected_x == 9 && slot_selected_y == 0)
		{
			seletedTowerIndex = 2;
		}
		else seletedTowerIndex = -1;

		if (towerSelected)
		{
			if (map[slot_selected_y][slot_selected_x] == 2)
			{
				if (towerIndex == 0) towers.push_back(*(new Sprite(tower1, slot_selected_x * 80 + 40, slot_selected_y * 80 + 40)));
				if (towerIndex == 1) towers.push_back(*(new Sprite(tower2, slot_selected_x * 80 + 40, slot_selected_y * 80 + 40)));
				if (towerIndex == 2) towers.push_back(*(new Sprite(tower3, slot_selected_x * 80 + 40, slot_selected_y * 80 + 40)));
				towerSelected = false;
				seletedTowerIndex = -1;
			}
		}

		if (!towerSelected && seletedTowerIndex != -1)
		{
			towerIndex = seletedTowerIndex;
			towerSelected = true;
		}
	}
	else
	{
		slot_selected->setPos(-1* 80 + 40, -1 * 80 + 40);
	}
}

void TowerDefenseGame::CalculateSelectedSlot()
{
	slot_selected_x = ((int)mouseX) / 80;
	slot_selected_y = ((int)mouseY) / 80;
}
double delta = 0;
int index = 0;
int dirInX = 0;
int dirInY = 0;
void TowerDefenseGame::CalculateEnemyMovement()
{
	int currentX = std::floor((enemies[0].getPos(0)-40) / 80);
	int yOffset = dirInY >= 0 ? -40 : 40;
	int currentY = std::floor((enemies[0].getPos(1)+yOffset) / 80);

	if(enemyWay[index + 1].x - currentX > 0) dirInX = 1;
	else if (enemyWay[index + 1].x - currentX < 0) dirInX = -1;
	else dirInX = 0;

	if (enemyWay[index + 1].y - currentY > 0) dirInY = 1;
	else if (enemyWay[index + 1].y - currentY < 0) dirInY = -1;
	else dirInY = 0;

	double now = glfwGetTime();
	delta += (now - lastTime) * enemy1_speed;
	lastTime = now;

	if (delta >= 1)
	{
		delta--;
		index++;
	}

	enemies[0].setPos(enemyWay[index].x * 80 + 40 + (delta * 80 * dirInX), enemyWay[index].y * 80 + 40 + (delta * 80 * dirInY));

	if (index == 21)
	{
		index = 0;
	}
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

	for (int i = 0; i < towers.size(); i++)
	{
		Sprite *tmp = &towers.at(i);
		tmp->Draw();
	}

	for (int i = 0; i < numbersDrawn.size(); i++)
	{
		Sprite *tmp = &numbersDrawn.at(i);
		tmp->Draw();
	}
}

double TowerDefenseGame::DistanceTo(Sprite* missile, Sprite* enemie)
{
	double x = missile->getPos(0) - enemie->getPos(0);
	double y = missile->getPos(1) - enemie->getPos(1);
	return sqrt((x*x) + (y*y));
}