#pragma once
#include "Zone.h"

class BlackSmith
{
public:
	void InPlayer(class UPlayer& _Player/*, int& Result*/);

	inline void SetParent(class UZone* _ParentZone)
	{
		ParentZone = _ParentZone;
	}

private:


	class UZone* ParentZone = nullptr;
};

