#include "pch.h"
#include <string>
#include <iostream>
#include <algorithm>

std::string words[100] = {
"rot",
"beautiful",
"produce",
"overconfident",
"curvy",
"hesitant",
"sister",
"waste",
"guide",
"power",
"rebel",
"short",
"sordid",
"weather",
"drum",
"cat",
"fine",
"regret",
"dinner",
"reflect",
"humor",
"digestion",
"fear",
"detect",
"tasty",
"violet",
"development",
"bless",
"fearful",
"belligerent",
"skin",
"collar",
"jelly",
"office",
"cub",
"victorious",
"imported",
"encouraging",
"spare",
"reject",
"brush",
"stamp",
"side",
"unequal",
"impulse",
"board",
"seed",
"warm",
"two",
"cough",
"noise",
"surprise",
"attempt",
"bear",
"meeting",
"plastic",
"exultant",
"caring",
"prefer",
"grotesque",
"nerve",
"soft",
"poke",
"coast",
"pretty",
"present",
"jam",
"tug",
"freezing",
"camera",
"sassy",
"hope",
"train",
"dashing",
"deceive",
"ignorant",
"twist",
"prepare",
"petite",
"tranquil",
"roll",
"glamorous",
"nippy",
"vegetable",
"petite",
"sweltering",
"lazy",
"next",
"test",
"end",
"remarkable",
"ready",
"tremble",
"enjoy",
"sprout",
"mice",
"beneficial",
"realise",
"breezy",
"grubby" };

void bubbleSort(std::string* arr, int len)
{
	for (unsigned int i = 0; i < len - 1; i++)
		for (unsigned int j = 0; j < len - i - 1; j++)
			if (arr[j].compare(arr[j + 1]) > 0)
				std::swap(arr[j], arr[j + 1]);
}

char a = 64;

int main()
{
	bubbleSort(words, 100);
	for (auto s : words)
		std::cout << s.c_str() << " ";
	std::cout << std::endl;
	return 0;
}