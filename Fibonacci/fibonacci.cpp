// fibonacci.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>

int main()
{
	int count, n1, n2, result;

	std::cout << "Fibonacci-Folge\n";
	std::cout << "Erste Zahl eingeben\n";
	std::cin >> n1;
	std::cout << "Zweite Zahl eingeben\n";
	std::cin >> n2;
	std::cout << "Länge der Folge eingeben\n";
	std::cin >> count;

	std::cout << "\n1. Zahl: " << n1 << "; 2. Zahl: " << n2 << "; ";
	for (int i = 0; i < count; i++)
	{
		result = n1 + n2;
		n1 = n2;
		n2 = result;
		std::cout << result << "; ";
	}
	return 0;
}

//class Fibonacci
//{
//#include "pch.h"
//#include <iostream>
//public:
//	int n1, n2, count, result;
//
//	Fibonacci() {};
//
//	void calculate(int n1,int n2,int count) {
//		for(int i = 0; i < count; i++)
//		{
//			result = n1 + n2;
//			n1 = n2;
//			n2 = result;
//			std::cout << result << "; ";
//		}
//	}
//	~Fibonacci() {};
//};

