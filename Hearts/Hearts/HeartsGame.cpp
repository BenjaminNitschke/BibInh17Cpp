#include "stdafx.h"
#include "HeartsGame.h"
#include <memory>
#include "Sprite.h"
#include "Player.h"
#include "Deck.h"
#include <iostream>
#include "StateMachine.h"

bool mouseClicked = false;

Deck* HeartsGame::deck;
Player HeartsGame::south;
Player HeartsGame::north;
std::shared_ptr<Sprite> HeartsGame::back;

StateMachine stateMachine;

void QueryMouseInput(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS)
	{
		if(stateMachine.GetState() != PLAYER_TURN || stateMachine.GetState() != COLOR_SELECTION)
			return;
		double x, y;
		glfwGetCursorPos(Game::pWindow, &x, &y);
		if (x > drawX - (float)HeartsGame::back->texture->width * scaling / 2 && x < drawX + (float)HeartsGame::back->texture->width * scaling / 2 &&
			y > drawY - (float)HeartsGame::back->texture->height * scaling / 2 && y < drawY + (float)HeartsGame::back->texture->height * scaling / 2 &&
			!HeartsGame::deck->deck.empty())
		{
			HeartsGame::south.hand.push_back(HeartsGame::deck->DrawTop());
			HeartsGame::south.SortHand();
		}

		else
			HeartsGame::south.SelectCard(x, y);
	}
}

HeartsGame::HeartsGame(int width, int height, const char * name) : Game(width, height, name)
{
	deck = new Deck();
	bg = std::make_shared<Sprite>("background.png", 640, 360);
	back = std::make_shared<Sprite>("./back.png", 0, 0, scaling);

	north = Player(640, 0, back);
	south = Player(640, 720, back);

	glfwSetMouseButtonCallback(pWindow, QueryMouseInput);

	Card::cardSelected = [this](std::shared_ptr<Card> card, int index)
	{
		if (ValidCard(card))
		{
			stack.push_back(card);
			card->sprite->MoveTo(pileX, pileY);
			south.hand.erase(south.hand.begin() + index);
			south.SortHand();
		}
	};

	deck->Shuffle();

	for (int i = 0; i < initialHandSize; i++)
	{
		north.hand.push_back(deck->DrawTop());
		south.hand.push_back(deck->DrawTop());
	}

	north.RepositionHand();
	south.SortHand();

	stack.push_back(deck->DrawTop());

	stack.back()->sprite->MoveTo(pileX, pileY);

	std::cout << std::endl << std::endl << "Deck created" << std::endl;
}

bool HeartsGame::ValidCard(std::shared_ptr<Card> card)
{
	if (stack.back()->value == card->value)
		return true;
	if (stack.back()->color == card->color)
		return true;
	if (card->value == jack && stack.back()->value != jack)
		return true;
	if (stack.back()->value == eight && card->value != eight)
		return false;
	return false;
}

void HeartsGame::RunHearts()
{
	Run([=]()
	{
		// render
		south.DrawHand();
		north.DrawHand();
		stack.back()->sprite->Draw();
		ReshuffleDeck();
		bg->Draw();
	});
}

void HeartsGame::ReshuffleDeck()
{
	if (deck->deck.empty() && stack.size() > 1)
	{
		for (int i = stack.size() - 1; i >= 1; --i)
		{
			deck->deck.push_back(stack[stack.size() - i - 1]);
			stack.erase(stack.end() - i - 1);
		}
		deck->Shuffle();
		std::cout << "The deck has been reshuffled. Now contains " << deck->deck.size() << " Cards" << std::endl;
	}
	else if (!deck->deck.empty())
	{
		back->MoveTo(drawX, drawY);
		back->Draw();
	}
}

