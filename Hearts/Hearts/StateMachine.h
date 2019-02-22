#pragma once

#define NONE            0b00000000
#define PLAYER_TURN     0b00000001
#define ENEMY_TURN      0b00000010
#define COLOR_SELECTION 0b00000100
#define JACK_ON_TOP     0b00001000

class StateMachine
{
private:
	int state;

public:
	StateMachine();
	void ChangeState(int newState);
	int GetState();
};
