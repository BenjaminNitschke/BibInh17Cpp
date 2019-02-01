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
		//StartTurn();
		player.hand[0]->cardGraphic->Draw();
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
			(*hand).push_back(deck.back());
			deck.pop_back();
		}		
	}
}

void CanastaGame::StartTurn()
{
	bool ended = false;
	if (roundNumber == 0)
		DealCards(&player.hand, 10);

	else DealCards(&player.hand, 2);
	std::cout << player.hand.size();
	
	while (!ended)
	{
		
	}
}

void CanastaGame::DrawCards()
{
	player.hand[0]->cardGraphic->Draw();
}

void Init()
{

}