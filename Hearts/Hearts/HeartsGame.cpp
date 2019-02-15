#include "stdafx.h"
#include "HeartsGame.h"
#include <memory>
#include "Sprite.h"
#include "Player.h"
#include "Deck.h"
#include <iostream>

bool mouseClicked = false;

HeartsGame::HeartsGame(int width, int height, const char * name) : Game(width, height, name)
{

}

std::shared_ptr<Sprite> back;
Deck deck;

Player north;
Player east;
Player south;
Player west;

std::vector<std::shared_ptr<Card>> cards;

void QueryMouseInput(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS)
	{
		double x, y;
		glfwGetCursorPos(Game::pWindow, &x, &y);
		if (x > drawX - (float)back->texture->width * scaling / 2 && x < drawX + (float)back->texture->width * scaling / 2 &&
			y > drawY - (float)back->texture->height * scaling / 2 && y < drawY + (float)back->texture->height * scaling / 2)
		{
			std::cout << "x: " << x << "drawX: " << drawX << std::endl;
			std::cout << "y: " << y << "drawY: " << drawY << std::endl;

			south.hand.push_back(deck.DrawTop());
			south.SortHand();
			south.RepositionHand();
		}

		else
			south.SelectCard(x, y);
	}
}

bool ValidCard(std::shared_ptr<Card> card)
{
	if (cards.back()->value == card->value)
		return true;
	if (cards.back()->color == card->color)
		return true;
	if (card->value == jack && cards.back()->value != jack)
		return true;
	if (cards.back()->value == eight && card->value != eight)
		return false;
	return false;
}

void HeartsGame::RunHearts()
{
	deck = Deck();

	glfwSetMouseButtonCallback(pWindow, QueryMouseInput);

	deck.Shuffle();
	back = std::make_shared<Sprite>("./back.png", 0, 0, scaling);

	north = Player(640, 0, back);
	south = Player(640, 720, back);

	for (int i = 0; i < initialHandSize; i++)
	{
		north.hand.push_back(deck.DrawTop());
		south.hand.push_back(deck.DrawTop());
	}

	cards.push_back(deck.DrawTop());
	cards.back()->sprite->MoveTo(pileX, pileY);

	Card::cardSelected = [](std::shared_ptr<Card> card, int index)
	{
		if (ValidCard(card))
		{
			cards.push_back(card);
			card->sprite->MoveTo(pileX, pileY);
			south.hand.erase(south.hand.begin() + index);
			south.SortHand();
			south.RepositionHand();
		}
	};

	south.SortHand();

	const auto bg = std::make_shared<Sprite>("background.png", 640, 360);

	double x, y;

	south.RepositionHand();
	north.RepositionHand();

	std::cout << std::endl << std::endl << "Deck created" << std::endl;

	Run([=]()
	{
		// render
		south.DrawHand();
		north.DrawHand();
		cards.back()->sprite->Draw();
		if (deck.deck.empty())
		{
			for (int i = 0; i < cards.size() - 1; i++)
			{
				deck.deck.push_back(cards[i]);
				cards.erase(cards.begin() + i);
				std::cout << "The deck has been reshuffled. Now contains " << deck.deck.size() << " Cards" << std::endl;
			}
		}
		else
		{
			back->MoveTo(drawX, drawY);
			back->Draw();
		}
		bg->Draw();
	});
}

