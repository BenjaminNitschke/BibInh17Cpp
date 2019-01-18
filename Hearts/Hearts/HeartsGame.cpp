#include "stdafx.h"
#include "HeartsGame.h"
#include <memory>
#include "Sprite.h"

HeartsGame::HeartsGame(int width, int height, const char * name) : Game(width, height, name)
{

}

void HeartsGame::RunHearts()
{
	const auto bg = std::make_shared<Sprite>("background.png", 640, 360);
	Run([=]()
	{
		bg->Draw();
	});
}

