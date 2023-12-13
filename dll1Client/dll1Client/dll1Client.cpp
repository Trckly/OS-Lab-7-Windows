#include <iostream>
#include <Windows.h>
#include "Threads.h"

int main()
{
	Threads threadManager;

	while (true) {
		std::cout << "Choose option: \n\t0 - Dynamic-Link Library connection\n\t1 - Static Library connection\n\n\t2 - Exit" << std::endl;
		int Input = 2;
		std::cin >> Input;

		switch (Input)
		{
		case 0:
			threadManager.ExecDynamicFuncs();
			break;

		case 1:
			threadManager.EXecStaticFuncs();
			break;

		case 2:
			return 0;

		default:
			std::cout << "Wrong option!" << std::endl;
			break;
		}
	}

	return 0;
}