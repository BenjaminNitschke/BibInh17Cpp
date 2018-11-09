#include "stdafx.h"
#include "FirstPersonShooter.h"
#include "FirstPersonShooterGame.h"
#include <Game.h>
#include <iostream>
using namespace std;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	auto game = std::make_shared<FirstPersonShooterGame>();//1280, 720, "Fps");
	game->RunTriangle();
	return 0;
}
