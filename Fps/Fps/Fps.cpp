#include "stdafx.h"
#include "Fps.h"
#include <iostream>
#include "Test.h"
using namespace std;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	int result = test(1, 2);
	cout << "result = " << result;
	return 0;
}
