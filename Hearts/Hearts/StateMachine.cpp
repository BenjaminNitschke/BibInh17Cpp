#include "stdafx.h"
#include "StateMachine.h"

StateMachine::StateMachine()
{
	state = NONE;
}

void StateMachine::ChangeState(int newState)
{
	state = newState;
}

int StateMachine::GetState()
{
	return state;
}
