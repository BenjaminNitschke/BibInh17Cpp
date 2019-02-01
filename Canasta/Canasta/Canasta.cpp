#include "stdafx.h"
#include "Canasta.h"
#include <memory>
#include "CanastaGame.h"
using namespace std;

int main()  
{
	 wWinMain(0, 0, 0, 0);
}
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	auto game = make_shared<CanastaGame>();
	//printf(game->deck[8]);
	game->RunGame();
	return 0;
}
