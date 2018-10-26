#pragma once
// Option 1 to define a byte
//#define byte unsigned char
typedef unsigned char byte;
class Quest
{
public:
	byte number;
	std::string text;
	std::vector<std::string> choices;
	Quest(std::string text, std::vector<std::string> choices)
		: text(text), choices(choices) {}
};

