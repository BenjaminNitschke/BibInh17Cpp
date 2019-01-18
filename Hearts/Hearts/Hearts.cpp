#include "stdafx.h"
#include "Hearts.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"
#include "HeartsGame.h"

void InitializeDeck();

int main()
{
	Deck deck = Deck();
	deck.Shuffle();

	Player north = Player();
	Player east = Player();
	Player south = Player();
	Player west = Player();

	while (!deck.deck.empty())
	{
		north.hand.push_back(deck.deck.back());
		deck.deck.pop_back();
		east.hand.push_back(deck.deck.back());
		deck.deck.pop_back();
		south.hand.push_back(deck.deck.back());
		deck.deck.pop_back();
		west.hand.push_back(deck.deck.back());
		deck.deck.pop_back();
	}

	south.SortHand();

	wWinMain(0, 0, 0, 0);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	const auto hearts = new HeartsGame(1280, 720, "Hearts");

	hearts->RunHearts();

	delete(hearts);
}
