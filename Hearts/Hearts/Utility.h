#pragma once

#include "stdafx.h"
#include <map>

#define HEARTS   100
#define SPADES   101
#define CLUBS    102
#define DIAMONDS 103

#define TWO      0
#define THREE    1
#define FOUR     2
#define FIVE     3
#define SIX      4
#define SEVEN    5
#define EIGHT    6
#define NINE     7
#define TEN      8
#define JACK     9
#define QUEEN    10
#define KING     11
#define ACE      12


class Utility
{
public:
	static const std::map<int, std::string> names;
	static const std::map<int, std::string> abbrev;
};
