#include "stdafx.h"
#include "Fps.h"
#include "Vector3.h"
#include <Game.h>
#include <iostream>
using namespace std;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	auto game = std::make_shared<Game>();
	game->RunTriangle();

	//TODO: Create Matrix struct
	// - Identity matrix
	// - Constructor to copy matrix
	// - Scale

	// - multiply with vector
	// - multiply with matrix
	// - optionale: rotation, translation

	return 0;
}
