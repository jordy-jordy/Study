
#include <iostream>
#include <vector>
#include "UVector.h"


class Skill
{

};


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		

	{
		UVector<int> stdvector;
		stdvector.reserve(10);

		for (int i = 0; i < 10; i++)
		{
			stdvector.push_back(i);
			std::cout << "push : " << stdvector[i] << std::endl;
			std::cout << "capacity : " << stdvector.capacity() << std::endl;
			std::cout << "size     : " << stdvector.size() << std::endl;
		}

		stdvector.clear();
	}

}
