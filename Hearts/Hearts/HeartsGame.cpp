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

Player north = Player();
Player east = Player();
Player south = Player();
Player west = Player();

void QueryMouseInput(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS)
	{
		double x, y;
		glfwGetCursorPos(Game::pWindow, (double*)&x, (double*)&y);
		south.SelectCard(x, y);
	}
}

void HeartsGame::RunHearts()
{
	glfwSetMouseButtonCallback(pWindow, QueryMouseInput);

	Deck deck = Deck();
	deck.Shuffle();

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

	std::cout << std::endl << std::endl << "Deck created" << std::endl;

	Run([=]()
	{
		// render
		south.DrawHand();
		bg->Draw();
	});
}

