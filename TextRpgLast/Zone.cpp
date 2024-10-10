#include "Zone.h"
#include <iostream>
#include <BaseSystem/EngineDebug.h>
#include <conio.h>


void UZone::InMsgPrint()
{
	system("cls");
	std::cout << GetName() << "에 입장했습니다.\n";
}

void UZone::ZonePrint()
{
	std::cout << GetName() << "에 체류중.\n";
}

bool UZone::IsConnecting(UZone* _ConnectingZone)
{
	for (size_t i = 0; i < static_cast<int>(Enums::MAXS::ZONELINKMAX); i++)
	{
		if (_ConnectingZone == ConnectingZones[i])
		{
			return true;
		}
	}

	return false;
}


bool UZone::InterConnecting(UZone* _LinkZone)
{
	_LinkZone->Connecting(this);
	this->Connecting(_LinkZone);

	return true;
}

bool UZone::Connecting(UZone* _LinkZone)
{
	if (this == _LinkZone)
	{
		MSGASSERT("자기자신을 자신에게 연결하려고 했습니다.");
		return false;
	}


	if (true == IsConnecting(_LinkZone))
	{
		MSGASSERT("이미 연결된 지역을 같은 지역에 또 연결하려고 했습니다.");
		return false;
	}

	for (size_t i = 0; i < static_cast<int>(Enums::MAXS::ZONELINKMAX); i++)
	{
		if (nullptr == ConnectingZones[i])
		{
			ConnectingZones[i] = _LinkZone;
			SelectMax += 1;
			return true;
		}
	}

	MSGASSERT("이미 모든 연결이 완결된 지역이라 연결에 실패했습니다.");
	return false;
}

UZone* UZone::ConnectingProgress()
{

	while (true)
	{
		ConnectingPrint();

		int Select = _getch();
		Select -= '0';

		if (Select >= 1 && Select <= SelectMax)
		{
			return ConnectingZones[Select - 1];
		}
		else if (Select <= (SelectMax + 1))
		{
			return this;
		}
	}

	return nullptr;
}

void UZone::ConnectingPrint()
{
	system("cls");

	int StartIndex = 1;

	for (size_t i = 0; i < static_cast<int>(Enums::MAXS::ZONELINKMAX); i++)
	{
		if (nullptr != ConnectingZones[i])
		{
			const char* NamePtr = ConnectingZones[i]->GetName();
			printf_s("%d. %s로 이동.\n", StartIndex, NamePtr);
			StartIndex += 1;
		}
	}

	printf_s("%d. %s로 돌아간다.\n", StartIndex, GetName());
}