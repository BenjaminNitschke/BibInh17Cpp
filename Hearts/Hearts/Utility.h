#pragma once

#include "stdafx.h"
#include <map>

const int hearts   = 100;
const int spades   = 101;
const int clubs    = 102;
const int diamonds = 103;

const int seven    =   5;
const int eight    =   6;
const int nine     =   7;
const int ten      =   8;
const int jack     =   9;
const int queen    =  10;
const int king     =  11;
const int ace      =  12;

const int idle = 0;
const int selected = 1;

const int initialHandSize = 7;

const int pileX = 480;
const int pileY = 360;

const int drawX = 800;
const int drawY = 360;

const float scaling = 0.25f;

const std::map<int, std::string> names = std::map<int, std::string>
{
	{std::pair<int,std::string>(hearts, "Hearts")},
	{std::pair<int,std::string>(spades, "Spades")},
	{std::pair<int,std::string>(clubs, "Clubs")},
	{std::pair<int,std::string>(diamonds, "Diamonds")},
	{std::pair<int,std::string>(seven, "Seven")},
	{std::pair<int,std::string>(eight, "Eight")},
	{std::pair<int,std::string>(nine, "Nine")},
	{std::pair<int,std::string>(ten, "Ten")},
	{std::pair<int,std::string>(jack, "Jack")},
	{std::pair<int,std::string>(queen, "Queen")},
	{std::pair<int,std::string>(king, "King")},
	{std::pair<int,std::string>(ace, "Ace")}

};

const std::map<int, std::string> abbrev = std::map<int, std::string>
{
	{std::pair<int,std::string>(hearts, "H")},
	{std::pair<int,std::string>(spades, "S")},
	{std::pair<int,std::string>(clubs, "C")},
	{std::pair<int,std::string>(diamonds, "D")},
	{std::pair<int,std::string>(seven, "7")},
	{std::pair<int,std::string>(eight, "8")},
	{std::pair<int,std::string>(nine, "9")},
	{std::pair<int,std::string>(ten, "10")},
	{std::pair<int,std::string>(jack, "J")},
	{std::pair<int,std::string>(queen, "Q")},
	{std::pair<int,std::string>(king, "K")},
	{std::pair<int,std::string>(ace, "A")}
};
