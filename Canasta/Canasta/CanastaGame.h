#pragma once
#include "Game.h"
#include "Card.h"
#include "Player.h"
#include <map>
#include <vector>
#include "Extension.h"
#include <memory>

class CanastaGame : public Game
{
private:
	int roundNumber = 0;
	std::shared_ptr<Sprite> playCardBtn = std::make_shared<Sprite>(std::make_shared<Texture>("./PNG/playCard.png"), 1100, 600, 2);
	std::vector<std::shared_ptr<Card>> cards = std::vector<std::shared_ptr<Card>>();
	std::vector<std::shared_ptr<Card>> cardsToDisplay = std::vector<std::shared_ptr<Card>>();
	Player player = Player();
public:
	std::vector<std::shared_ptr<Card>> deck = std::vector<std::shared_ptr<Card>>();
	CanastaGame();
	~CanastaGame()
	{
		
	}	
	std::shared_ptr<Card> CheckIfPlayerCardIsClicked();
	void HighlightCard(std::shared_ptr<Card> card);
	void HandlePlayerInput();
	bool ClickDetection(double minX, double maxX, double minY, double maxY);
	void PlaceSelectedCards();
	void RunGame();
	void Init();
	void DealCards(std::vector<std::shared_ptr<Card>>* hand, int amount);
	void StartTurn();
	void DrawCards();
};