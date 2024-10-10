#pragma once
#include "Object.h"
#include "Enums.h"

class UZone : public UObject
{
public:
	void InMsgPrint();
	void ZonePrint();

	bool InterConnecting(UZone& _LinkZone)
	{
		return InterConnecting(&_LinkZone);
	}
	bool InterConnecting(UZone* _LinkZone);
	bool Connecting(UZone* _LinkZone);
	bool IsConnecting(UZone* _LinkZone);
	void ConnectingPrint();

	UZone* ConnectingProgress();

	bool IsConnectEmpty()
	{
		return SelectMax == 0;
	}

	int GetSelectMax()
	{
		return SelectMax;
	}


	virtual UZone* InPlayer()
	{
		return nullptr;
	}

protected:
	inline UZone* GetZone(int _Index)
	{
		return ConnectingZones[_Index];
	}

private:
	UZone* ConnectingZones[static_cast<int>(Enums::MAXS::ZONELINKMAX)] = { nullptr, };
	int SelectMax = 0;

};