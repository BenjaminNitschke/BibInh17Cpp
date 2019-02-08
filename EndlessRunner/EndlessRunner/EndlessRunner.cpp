#include "stdafx.h"
#include <memory>
#include "EndlessRunner.h"
#include "EndlessRunnerGame.h"
#include <ctime>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	srand(time(nullptr));

	auto game = std::make_shared<EndlessRunnerGame>(1920, 1080, "Endless Runner");
	game->RunEndlessRunner();
	return 0;
}

int main()
{
	wWinMain(nullptr, nullptr, nullptr, 0);
}