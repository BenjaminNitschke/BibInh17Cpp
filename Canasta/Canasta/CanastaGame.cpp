#include "stdafx.h"
#include "CanastaGame.h"

void CanastaGame::RunGame()
{
	Run([=]()
	{
		deck[0]->cardGraphic->Move(1, 1);
		deck[0]->cardGraphic->Draw();

	});
}

