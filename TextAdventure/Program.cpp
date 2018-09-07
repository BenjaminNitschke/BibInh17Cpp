#include "stdafx.h"
#include "Quest.h"
using namespace std;
int main()
{
	int* pointerToNumber = new int[10];
	pointerToNumber[0] = 1;
	pointerToNumber[1] = 2;
	pointerToNumber[2] = 3;

	cout << *(pointerToNumber++) << endl;
	delete pointerToNumber;

	vector<Quest> quests;
	quests.push_back(Quest(
		"Welcome to my great text adventure",
		vector<string> { "1 go on", "2 exit"}));
	quests.push_back(Quest("bla bla",
		vector<string> { "1 go back", "2 exit"}));
	Quest currentQuest = quests[0];
	while (true)
	{
		cout << currentQuest.text.c_str() << endl;
		cout << "What do you want to do?";
		for (auto choice : currentQuest.choices)
			cout << choice.c_str() << ", ";
		cout << endl;
		unsigned int number;
		cin >> number;
		if (number == 1)
			currentQuest = quests[1];
		else
			break;
	}
}