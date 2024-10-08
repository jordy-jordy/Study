#pragma once
#include "ContentsConst.h"
#include <BaseSystem/EngineDebug.h>
#include <iostream>


class UObjects
{
public:
	void SetName(const char* const _Name);
	const char* GetName()
	{
		return Name;
	}

protected:
private:
	char Name[MaxNameLen] = "NONE";

};

