#include "stdafx.h"
#include "FirstPersonShooter.h"
#include "FirstPersonShooterGame.h"
#include <Game.h>
#include <iostream>
#include "Vector3.h"

using namespace std;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	auto game = std::make_shared<FirstPersonShooterGame>();//1280, 720, "Fps");
	game->RunTriangle();

	auto a = Vector3(1, 1, 1);
	auto b = Vector3(1, 1, 1);
	auto cout <<

	//TODO: Create Matrix struct
	//- Identity matrix
	//- Constructor to copy matrix
	//- Scale
	//- multiply with vector
	//- multiply with matrix
	//- optional: rotation, translation
	return 0;
}
