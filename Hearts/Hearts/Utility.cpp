#include "stdafx.h"
#include <map>
#include "Utility.h"
const std::map<int, std::string> Utility::names = std::map<int, std::string>
{
	{std::pair<int,std::string>(HEARTS, "Hearts")},
	{std::pair<int,std::string>(SPADES, "Spades")},
	{std::pair<int,std::string>(CLUBS, "Clubs")},
	{std::pair<int,std::string>(DIAMONDS, "Diamonds")},
	{std::pair<int,std::string>(TWO, "Two")},
	{std::pair<int,std::string>(THREE, "Three")},
	{std::pair<int,std::string>(FOUR, "Four")},
	{std::pair<int,std::string>(FIVE, "Five")},
	{std::pair<int,std::string>(SIX, "Six")},
	{std::pair<int,std::string>(SEVEN, "Seven")},
	{std::pair<int,std::string>(EIGHT, "Eight")},
	{std::pair<int,std::string>(NINE, "Nine")},
	{std::pair<int,std::string>(TEN, "Ten")},
	{std::pair<int,std::string>(JACK, "Jack")},
	{std::pair<int,std::string>(QUEEN, "Queen")},
	{std::pair<int,std::string>(KING, "King")},
	{std::pair<int,std::string>(ACE, "Ace")}

};

const std::map<int, std::string> Utility::abbrev = std::map<int, std::string>
{
	{std::pair<int,std::string>(HEARTS, "H")},
	{std::pair<int,std::string>(SPADES, "S")},
	{std::pair<int,std::string>(CLUBS, "C")},
	{std::pair<int,std::string>(DIAMONDS, "D")},
	{std::pair<int,std::string>(TWO, "2")},
	{std::pair<int,std::string>(THREE, "3")},
	{std::pair<int,std::string>(FOUR, "4")},
	{std::pair<int,std::string>(FIVE, "5")},
	{std::pair<int,std::string>(SIX, "6")},
	{std::pair<int,std::string>(SEVEN, "7")},
	{std::pair<int,std::string>(EIGHT, "8")},
	{std::pair<int,std::string>(NINE, "9")},
	{std::pair<int,std::string>(TEN, "10")},
	{std::pair<int,std::string>(JACK, "J")},
	{std::pair<int,std::string>(QUEEN, "Q")},
	{std::pair<int,std::string>(KING, "K")},
	{std::pair<int,std::string>(ACE, "A")}
};