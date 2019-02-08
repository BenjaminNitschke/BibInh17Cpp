#pragma once
#include <functional>

class Game
{
private:
	void* window;
public:
	Game(const char* title);
	~Game();
	void Run(std::function<void()> renderFunction);
	void RunTriangle();
	int viewportWidth;
	int viewportHeight;
	static bool leftPressed;
	static bool rightPressed;
	static bool upPressed;
	static bool downPressed;
	static bool turnLeftPressed;
	static bool turnRightPressed;
	static bool spacePressed;
	double time = 0;
	double lastTime = 0;
	double timeThisTick = 0.001;
	float GetTimeDelta() { return static_cast<float>(timeThisTick); }
};