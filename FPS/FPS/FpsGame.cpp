#include "stdafx.h"
#include "FpsGame.h"

FpsGame::FpsGame(int width, int height, const char * name) : Game(width, height, name)
{
	
}

FpsGame::~FpsGame()
{
}

void FpsGame::RunGame()
{
	Run([=]()
	{
		ground->Draw();
	});
}
