#include "stdafx.h"
#include "TowerDefenseGame.h"
#include "Sprite.h"
#include <memory>
#include <vector>

TowerDefenseGame::TowerDefenseGame(int width, int height, const char* name)
{
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

	towers.push_back(Tower(7, 0, 1, 1, Sprite(tower1, 0, 0)));
	towers.push_back(Tower(8, 0, 1, 1, Sprite(tower2, 0, 0)));
	towers.push_back(Tower(9, 0, 1, 1, Sprite(tower3, 0, 0)));

	numbersDrawn.push_back(Sprite(numbers.at(5), 7 * 80 + 67 - 8 * 0, 0 * 80 + 68));
	numbersDrawn.push_back(Sprite(numbers.at(1), 8 * 80 + 67 - 8 * 1, 0 * 80 + 68));
	numbersDrawn.push_back(Sprite(numbers.at(0), 8 * 80 + 67 - 8 * 0, 0 * 80 + 68));
	numbersDrawn.push_back(Sprite(numbers.at(2), 9 * 80 + 67 - 8 * 1, 0 * 80 + 68));
	numbersDrawn.push_back(Sprite(numbers.at(0), 9 * 80 + 67 - 8 * 0, 0 * 80 + 68));

	goldNumberPart1 = 0;
	goldNumberPart2 = 0;
	goldNumberPart3 = 0;

	xGold = 10 * 80 + 50;
	yGold = 0 * 80 + 68;

	for (int i = 0; i < 10; i++)
	{
		goldNumber1.push_back(*(new Sprite(numbers.at(i), -8, -8)));
	}

	for (int i = 0; i < 10; i++)
	{
		goldNumber2.push_back(*(new Sprite(numbers.at(i), -8, -8)));
	}

	for (int i = 0; i < 10; i++)
	{
		goldNumber3.push_back(*(new Sprite(numbers.at(i), -8, -8)));
	}

	goldNumber1[goldNumberPart1].setPos(xGold + 16, yGold);
	goldNumber2[goldNumberPart2].setPos(xGold + 8, yGold);
	goldNumber3[goldNumberPart3].setPos(xGold, yGold);

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

	enemies.push_back(Enemy(0, 0, 100, 1, Sprite(enemy1, 0, 0), enemyWay, 0));
	enemies.push_back(Enemy(0, 0, 100, 2, Sprite(enemy2, 0, 0), enemyWay, 0));
	enemies.push_back(Enemy(0, 0, 100, 3, Sprite(enemy3, 0, 0), enemyWay, 0));
	enemies.push_back(Enemy(0, 0, 100, 4, Sprite(enemy2, 0, 0), enemyWay, 0));
	enemies.push_back(Enemy(0, 0, 100, 5, Sprite(enemy1, 0, 0), enemyWay, 0));

	//lines.push_back(*(new Line(Point(0, 0), Point(100, 100))));
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
		CalculateLines();
		DrawAll();
	});
}

void TowerDefenseGame::CalculateLines()
{
	if(towers.size() > 3)
		for (int i = 3; i < towers.size(); i++)
		{
			towers[i].CalculateLines();
		}

	/*if (towers.size() > 3)
		testline.SetPoint(1, enemies[0].GetPos().x, enemies[0].GetPos().y);*/
}

void TowerDefenseGame::ChangeGoldAmount(int number)
{
	goldNumber1[goldNumberPart1].setPos(-8, -8);
	goldNumber2[goldNumberPart2].setPos(-8, -8);
	goldNumber3[goldNumberPart3].setPos(-8, -8);

	goldNumberPart1 = number % 1000 / 100;
	goldNumberPart2 = number % 100 / 10;
	goldNumberPart3 = number % 10;

	goldNumber1[goldNumberPart1].setPos(xGold, yGold);
	goldNumber2[goldNumberPart2].setPos(xGold + 8, yGold);
	goldNumber3[goldNumberPart3].setPos(xGold + 16, yGold);
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
				if (towerIndex == 0) towers.push_back(Tower(slot_selected_x, slot_selected_y, 1, 1, *(new Sprite(tower1, 0, 0))));
				if (towerIndex == 1) towers.push_back(Tower(slot_selected_x, slot_selected_y, 1, 1, *(new Sprite(tower2, 0, 0))));
				if (towerIndex == 2) towers.push_back(Tower(slot_selected_x, slot_selected_y, 1, 1, *(new Sprite(tower3, 0, 0))));
				towerSelected = false;
				seletedTowerIndex = -1;
				if (towers.size() == 4)
					testline = Line(Point(slot_selected_x * 80 + 40, slot_selected_y * 80 + 40), Point(enemies[0].GetPos().x, enemies[0].GetPos().y));
				for (int i = 0; i < enemies.size(); i++)
					towers[towers.size() - 1].AddEnemy(&enemies[i]);
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

int gold = 0;

void TowerDefenseGame::CalculateEnemyMovement()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].Move();
	}
	gold = towers.size()-3;
	ChangeGoldAmount(gold);
}

float GetOpenGLX(int px) {
	int centerX = px - (int)SCREEN_WIDTH / 2;
	return (centerX / SCREEN_WIDTH)*2.0f;
}
float GetOpenGLY(int py) {
	int centerY = py - (int)SCREEN_HEIGHT / 2;
	return (centerY / SCREEN_HEIGHT)*(-2.0f);
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

	//if (iPressed)
	//{
	//	for (int i = 0; i < lines.size(); i++)
	//	{
	//		lines.at(i).Draw();
	//	}
	//}

	/*if (towers.size() > 3)
		testline.Draw();*/

	for (int i = 0; i < towers.size(); i++)
	{
		towers[i].Draw();
	}

	

	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].Draw();
	}
	
	for (int i = 0; i < numbersDrawn.size(); i++)
	{
		numbersDrawn[i].Draw();
	}
	
	

	goldNumber1[goldNumberPart1].Draw();
	goldNumber2[goldNumberPart2].Draw();
	goldNumber3[goldNumberPart3].Draw();
}

double TowerDefenseGame::DistanceTo(Sprite* missile, Sprite* enemie)
{
	double x = missile->getPos(0) - enemie->getPos(0);
	double y = missile->getPos(1) - enemie->getPos(1);
	return sqrt((x*x) + (y*y));
}
