#pragma once
#include "Game.h"
namespace Fps
{
	class FpsGame : Game
	{
	public:
		FpsGame() :Game() {};
		void PlayGame() override { Run([]() {}); }
	};
}