#include "stdafx.h"
#include "Fps.h"
#include "FpsGame.h"
#include "Vector3.h"
#include <iostream>
#include <memory>
using namespace std;

int main() { return wWinMain(NULL, NULL, NULL, 0); }
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	//auto game = std::make_shared<FpsGame>();
	//game->RunTriangle();
	//TODO: also add sprite and texture classes!
	auto a = Vector3(1, 0, 0);//2, 3);
	auto b = Vector3(0, 1, 0);//2, 3, 4);
	cout << a.ToString() << "+" << b.ToString() << "=" << (a+b).ToString() << endl;
	cout << a.ToString() << "-" << b.ToString() << "=" << (a-b).ToString() << endl;
	cout << "-" << a.ToString() << "=" << (-a).ToString() << endl;
	cout << a.ToString() << "*" << 5 << "=" << (a*5).ToString() << endl;
	cout << a.ToString() << " dot " << b.ToString() << "=" << (a.DotProduct(b)).ToString() << endl;
	cout << a.ToString() << " cross " << b.ToString() << "=" << (a.CrossProduct(b)).ToString() << endl;
	cout << a.ToString() << " length " << "=" << a.Length() << endl;

	//TODO: Create Matrix struct
	//- Identity matrix
	//- Constructor to copy matrix
	//- Scale
	//- multiply with vector
	//- multiply with matrix
	//- optional: rotation, translation

	return 0;
}
