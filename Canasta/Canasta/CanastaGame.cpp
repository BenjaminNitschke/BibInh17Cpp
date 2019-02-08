#include "stdafx.h"
#include "CanastaGame.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

bool test = true;
bool once = true;
void CanastaGame::RunGame()
{
	Run([=]()
	{			
		player.DisplayHand();
	});
}

CanastaGame::CanastaGame() : Game("Canasta")
{
	//Load all Card PNG
	for (int c = hearts; c <= clubs; c++)
		for (int v = 2; v <= ace; v++)
			cards.push_back(std::make_shared<Card>(valueToChar.at(v), intToColor.at(c), v));
	//Load Jokers
	cards.push_back(std::make_shared<Card>("Joker", "", 20));

	//Create Deck -> 2 times all cards
	for (unsigned int i = 0; i < cards.size(); i++)
	{
		deck.push_back(cards[i]);
		deck.push_back(cards[i]);
	}

	//Shuffle deck
	std::shuffle(deck.begin(), deck.end(), std::default_random_engine(std::time(nullptr)));
	Init();
}

void CanastaGame::DealCards(std::vector<std::shared_ptr<Card>>* hand, int amount)
{
	if (deck.size() == 0)
		//TODO Game Over
		printf("");
	else
	{
		std::cout << "Deck size: " << deck.size() << std::endl;
		for (int i = 0; i < amount; i++)
		{
			//std::cout << deck.back()->color.c_str() << std::endl;
			(*hand).push_back(std::make_shared<Card>(deck.back()));
			//std::cout << deck.back()->color.c_str() << std::endl;
			deck.pop_back();			 
		}		
	}
}

void CanastaGame::StartTurn()
{
	bool ended = false;
	
	//if(!buying)
	DealCards(&player.hand, 2);
	
	while (!ended)
	{
		
		ended = true;
	}
}

void CanastaGame::DrawCards()
{
	
}

void CanastaGame::Init()
{
	DealCards(&player.hand, 15);
	player.SortHand();	
	player.ArrangeHand();
	player.DisplayHand();
}