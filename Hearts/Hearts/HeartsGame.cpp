#include "stdafx.h"
#include "HeartsGame.h"
#include <memory>
#include "Sprite.h"
#include "Player.h"
#include "Deck.h"
#include <iostream>
#include "Trick.h"

bool mouseClicked = false;

HeartsGame::HeartsGame(int width, int height, const char * name) : Game(width, height, name)
{

}

std::shared_ptr<Sprite> back;

Player north;
Player east;
Player south;
Player west;

void QueryMouseInput(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS)
	{
		float x, y;
		glfwGetCursorPos(Game::pWindow, (double*)&x, (double*)&y);
		south.SelectCard(x, y);
	}
}

void HeartsGame::RunHearts()
{
	glfwSetMouseButtonCallback(pWindow, QueryMouseInput);

	Deck deck = Deck();
	deck.Shuffle();
	back = std::make_shared<Sprite>("./back.png", 0, 0, scaling);

	north = Player(640, 0, back);
	east = Player(1280, 360, back);
	south = Player(640, 720, back);
	west = Player(0, 360, back);

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

	const auto bg = std::make_shared<Sprite>("background.png", 640, 360);

	double x, y;

	south.RepositionHand();
	north.RepositionHand();

	std::cout << std::endl << std::endl << "Deck created" << std::endl;

	Card::addToTrick = [](Trick* trick, Player* player, Card* card) { trick->Add(player, card); };

	Trick currentTrick = Trick();

	Run([=, &currentTrick]()
	{
		if (currentTrick.Empty())
		{
			currentTrick = Trick();
			Card::addToTrick(&currentTrick, &west, west.hand[0].get());
			Card::sortAndRemove(&west, west.hand[0].get());
			Card::addToTrick(&currentTrick, &north, north.hand[0].get());
			Card::sortAndRemove(&north, north.hand[0].get());
			Card::addToTrick(&currentTrick, &east, east.hand[0].get());
			Card::sortAndRemove(&east, east.hand[0].get());
			std::cout << currentTrick.cards.size() << std::endl;
		}

		// render
		south.DrawHand();
		north.DrawHand();
		if(!currentTrick.Empty())
			currentTrick.Draw();
		bg->Draw();
	});
}

