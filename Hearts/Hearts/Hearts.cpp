#include "stdafx.h"
#include "Hearts.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"
#include "HeartsGame.h"

void InitializeDeck();

int main()
{
	wWinMain(0, 0, 0, 0);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	const auto hearts = new HeartsGame(1280, 720, "Hearts");

	hearts->RunHearts();

	delete(hearts);
}
