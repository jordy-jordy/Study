
#include <iostream>
#include <list>
#include "UList.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

											
								
	{
		UList Newint;
		Newint.push_back(0);
		Newint.push_back(1);
		Newint.push_back(2);
		Newint.push_back(3);
		Newint.push_back(4);
		Newint.push_front(9);
		Newint.push_front(10);
		Newint.push_front(100);
		Newint.push_front(11);

		int a = 0;
	}
}
