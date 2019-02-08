#pragma once
#include "Game.h"
#include "Card.h"
#include "Player.h"
#include <map>
#include <vector>
#include "Extension.h"

class CanastaGame : public Game
{
private:
	int roundNumber = 0;
	std::vector<std::shared_ptr<Card>> cards = std::vector<std::shared_ptr<Card>>();
	std::vector<std::shared_ptr<Card>> cardsToDisplay = std::vector<std::shared_ptr<Card>>();
	Player player = Player();
public:
	std::vector<std::shared_ptr<Card>> deck = std::vector<std::shared_ptr<Card>>();
	CanastaGame();
	~CanastaGame()
	{
		
	}	
	void RunGame();
	void Init();
	void DealCards(std::vector<std::shared_ptr<Card>>* hand, int amount);
	void StartTurn();
	void DrawCards();
};