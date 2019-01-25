#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

string words[10];
int arraySize;

char CreateChar()
{
	auto tmp = 0;
	tmp = rand() % 27 + 64;
	return tmp;
}

string CreateWord() 
{
	string word;

	for (int i = 0; i < 28; i++)
	{
		word += CreateChar();
	}
	
	return word;
}

void BubbleSort(string myArray[]) 
{
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = i + 1; j < arraySize - 1; j++)
		{
			if (myArray[j].compare(myArray[j + 1]) > 0) 
			{
				swap(myArray[j], myArray[j + 1]); 
			}
		}
	}
}

int main()
{
	srand(time(nullptr));

	arraySize = words->size();

	for (int i = 0; i < 10; i++) 
	{
		words[i] = CreateWord();
		cout << words[i].c_str() << endl;
	}

	BubbleSort(words);
	cout << "" << endl;

	for (int i = 0; i < 10; i++) 
	{
		cout << words[i].c_str() << endl;
	}

	return 0;
}
