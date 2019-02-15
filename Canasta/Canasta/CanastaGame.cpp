#include "stdafx.h"
#include "CanastaGame.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <iostream>

void CanastaGame::RunGame()
{
	Run([=]()
	{	
		//std::cout << posX << "  :  " << posY << std::endl;
		if (leftMouseButtonClicked)
		{
			HandlePlayerInput();
		}
		playCardBtn->Draw();
		player.DisplayHand();
		leftMouseButtonClicked = false;
	});
}

void CanastaGame::HandlePlayerInput()
{
	if (player.hand.size() > 0)
	{
		auto clickedCard = CheckIfPlayerCardIsClicked();
		if (clickedCard != NULL)
		{
			HighlightCard(clickedCard);
		}
	}	
	if (ClickDetection(playCardBtn->x - playCardBtn->GetWidth() / 2, playCardBtn->x + playCardBtn->GetWidth() / 2, playCardBtn->y - playCardBtn->GetHeight() / 2, playCardBtn->y + playCardBtn->GetHeight() / 2))
	{
		PlaceSelectedCards();
	}
	
}

void CanastaGame::PlaceSelectedCards()
{
	
	for (int i = 0; i < player.selectedCards.size(); i++)
	{
		player.selectedCards[i]->cardGraphic->x = viewportWidth / 2; 
		player.selectedCards[i]->cardGraphic->y = viewportHeight / 2; 
	}
	for (int i = 0; i < player.selectedCards.size(); i++)
	{		
		player.selectedCards[i]->isPlaced = true;
		
	}
	for (int i = 0; i < player.selectedCards.size(); i++)
	{
		player.hand.erase(std::remove(player.hand.begin(), player.hand.end(), player.selectedCards[i]), player.hand.end());
	}
	player.selectedCards.clear();
	player.ArrangeHand();
}

std::shared_ptr<Card> CanastaGame::CheckIfPlayerCardIsClicked()
{
	double cardWidth = player.hand[0]->cardGraphic->GetWidth() / 16;
	double cardHeight = player.hand[0]->cardGraphic->GetHeight() / 16;

	for (int i = 0; i < player.hand.size(); i++)
	{
		auto card = player.hand[i]->cardGraphic;

		if (ClickDetection(card->x - cardWidth, card->x + cardWidth, card->y - cardHeight, card->y + cardHeight))
		{
			return player.hand[i];
		}
	}
	return NULL;
}

void CanastaGame::HighlightCard(std::shared_ptr<Card> card)
{
	if (card->isPlaced)return;

	if (card->isHighlightable)
	{
		card->cardGraphic->y -= 50;
		card->isHighlightable = false;
		player.selectedCards.push_back(card);
	}
	else
	{
		card->cardGraphic->y += 50;
		card->isHighlightable = true;
		player.selectedCards.erase(std::remove(player.selectedCards.begin(), player.selectedCards.end(), card), player.selectedCards.end());
	}
}

bool CanastaGame::ClickDetection(double minX, double maxX, double minY, double maxY)
{
	if (posX >= minX &&
		posX <= maxX &&
		posY >= minY &&
		posY <= maxY)
	{
		return true;
	}
	return false;
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
			(*hand).push_back(std::make_shared<Card>(deck.back()));
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