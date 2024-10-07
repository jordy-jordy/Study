#pragma once
#include "ContentsConst.h"
#include <BaseSystem/EngineDebug.h>
#include <iostream>

class UObject
{
public:
	void SetName(const char* const _Name);
	inline const char* GetName()
	{
		return Name;
	}

private:
	char Name[NAMELEN] = "NONE";
};