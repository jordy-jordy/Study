#pragma once
#include "ContentsConst.h"
#include <BaseSystem/EngineDebug.h>
#include <iostream>


class UObjects
{
public:
	const char* GetName()
	{
		return Name;
	}

	void SetName(const char* const _Name);

protected:
private:
	char Name[MaxNameLen] = "NONE";

};

