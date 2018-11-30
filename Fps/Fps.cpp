#include "stdafx.h"
#include "Fps.h"
#include "Vector3.h"
#include "FpsGame.h"
#include <iostream>
using namespace std;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	auto game = std::make_shared<Fps::FpsGame>();
	game->RunGame();

	return 0;
}
