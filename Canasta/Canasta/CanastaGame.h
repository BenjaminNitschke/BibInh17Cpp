#pragma once
#include "Game.h"
#include "Card.h"
#include <map>
#include <vector>

const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

const int hearts = 0;
const int diamonds = 1;
const int spades = 2;
const int clubs = 3;

const std::map<int, std::string> valueToChar = std::map<int, std::string>
{					
	{std::pair<int, std::string>(2, "2")},
	{std::pair<int, std::string>(3, "3")},
	{std::pair<int, std::string>(4, "4")},
	{std::pair<int, std::string>(5, "5")},
	{std::pair<int, std::string>(6, "6")},
	{std::pair<int, std::string>(7, "7")},
	{std::pair<int, std::string>(8, "8")},
	{std::pair<int, std::string>(9, "9")},
	{std::pair<int, std::string>(10, "10")},
	{std::pair<int, std::string>(11, "J")},
	{std::pair<int, std::string>(12, "Q")},
	{std::pair<int, std::string>(13, "K")},
	{std::pair<int, std::string>(14, "A")}
};

const std::map<int, std::string> intToColor = std::map<int, std::string>
{					
	{std::pair<int, std::string>(0, "H")},
	{std::pair<int, std::string>(1, "D")},
	{std::pair<int, std::string>(2, "S")},
	{std::pair<int, std::string>(3, "C")}
};

class CanastaGame : public Game
{
	
public:
	std::vector<std::shared_ptr<Card>> deck = std::vector<std::shared_ptr<Card>>();
	CanastaGame() : Game("Canasta")
	{
		for (int i = 0; i < 2; i++)
			for (int c = hearts; c <= clubs; c++)
				for (int v = 2; v <= ace; v++)
					deck.push_back(std::make_shared<Card>(valueToChar.at(v), intToColor.at(c)));
	}
	~CanastaGame()
	{
		
	}	
	void RunGame();
};