#include "stdafx.h"
#include "Hearts.h"
#include "Deck.h"

void InitializeDeck();

Deck deck;

int main()
{
	deck = Deck();
	deck.PrintDeck();
	wWinMain(0, 0, 0, 0);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	return 0;
}
