#include "stdafx.h"
#include <memory>
#include <vector>
#include "GLFW/glfw3.h"
#include "GameObject.h"
#include "Vector3.h"
#include "Game.h"
#include "Testphysics.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	auto testphysics = std::make_shared<Testphysics>();
	testphysics->RunTestphysics();
	return 0;
}