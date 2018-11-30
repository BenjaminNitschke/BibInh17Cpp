#include "stdafx.h"
#include "FirstPersonShooter.h"
#include "FirstPersonShooterGame.h"
#include <Game.h>
#include <iostream>
#include "Vector3.h"

using namespace std;

int main() 
{
	return wWinMain(NULL, NULL, NULL, 0);
}
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	auto game = std::make_shared<FirstPersonShooterGame>();//1280, 720, "Fps");
	game->RunGame();

	auto a = Vector3(1, 1, 1);
	auto b = Vector3(1, 1, 1);
	cout << a.ToString() << " + " << b.ToString() << " = " << (a + b).ToString() << endl;
	cout << a.ToString() << " - " << b.ToString() << " = " << (a - b).ToString() << endl;
	cout << "-" << a.ToString() << " = " << (-a).ToString() << endl;
	cout << a.ToString() << " * " << 5 << " = " << (a * 5).ToString() << endl;
	cout << a.ToString() << " dot " << b.ToString() << " = " << (a.DotProduct(b)).ToString() << endl;
	cout << a.ToString() << " cross " << b.ToString() << " = " << (a.CrossProduct(b)).ToString() << endl;
	cout << a.ToString() << " length " << "= " << a.Length() << endl;

	/*auto m = Matrix();
	cout << "Identity matrix: " << m.ToString() << endl;
	auto m2 = Matrix(m);
	m2 = m.Scale(Vector3(2, 2, 2));
	cout << "Scaled matrix: " << m2.ToString() << endl;
	cout << "matrix * vector: " << (m2*a)*/

	//TODO: Create Matrix struct
	//- Identity matrix
	//- Constructor to copy matrix
	//- Scale
	//- multiply with vector
	//- multiply with matrix
	//- optional: rotation, translation
	return 0;
}
