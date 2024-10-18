
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include "UMap.h"




class MapNode
{
public:
	MapNode* Parent;
	MapNode* LeftChild;
	MapNode* RightChild;
};

class OctMapNode
{
public:
	MapNode* Parent;
	MapNode* Childs[8];
};

class QuadMapNode
{
public:
	MapNode* Parent;
	MapNode* Childs[4];
};


class BiMapNode
{
public:
	MapNode* Parent;
	MapNode* LeftChild;
	MapNode* RightChild;
};


class greater
{
public:
	bool operator()(int _left, int _Right)
	{
		return _left < _Right;
	}
};



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	{
		std::vector<int> Test;
		std::vector<int>::iterator StartIter = Test.begin();
		std::vector<int>::iterator EndIter = Test.end();

		for (; StartIter != EndIter; ++StartIter)
		{
			int Value = *StartIter;
		}
	}

	{
		std::list<int> Test;
		std::list<int>::iterator StartIter = Test.begin();
		std::list<int>::iterator EndIter = Test.end();

		for (; StartIter != EndIter; ++StartIter)
		{
			int Value = *StartIter;
		}
	}


	{
		std::set<int> TestSet;

		std::map<int, int, std::greater<int>> TestMap;


		std::pair<int, int> PairValue;
		PairValue.first = 10;
		PairValue.second = 10;
		TestMap.insert(PairValue);
		TestMap.insert({ 10, 20 });
		TestMap.insert(std::make_pair(10, 0));
		TestMap.insert(std::map<int, int>::value_type(2, 0));
		TestMap.insert(std::make_pair(5, 0));
		TestMap.insert(std::make_pair(7, 0));
		TestMap.insert(std::make_pair(15, 0));

		std::map<int, int>::iterator FindIter = TestMap.find(7);
		FindIter->first;
		FindIter->second;

		std::map<int, int>::iterator StartIter = TestMap.begin();
		std::map<int, int>::iterator EndIter = TestMap.end();

		for (; StartIter != EndIter; ++StartIter)
		{
			std::cout << StartIter->first << std::endl;
		}

	}

	{
		UMap TestMap;

		UPair PairValue = { 10, 2 };
		PairValue.first = 10;
		PairValue.second = 2;

		TestMap.insert({ 10, 0 });
		TestMap.insert({ 2, 0 });
		TestMap.insert(Umake_pair(6, 0));
		TestMap.insert(Umake_pair(5, 0));
		TestMap.insert(Umake_pair(4, 0));
		TestMap.insert(Umake_pair(7, 9999));
		TestMap.insert(Umake_pair(15, 0));

	}
}

