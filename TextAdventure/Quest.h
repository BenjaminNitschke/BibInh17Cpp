#pragma once
class Quest
{
public:
	std::string text;
	std::vector<std::string> choices;
	Quest(std::string text, std::vector<std::string> choices)
		: text(text), choices(choices) {}
};

