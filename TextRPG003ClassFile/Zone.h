#pragma once
#include "StatusUnit.h"
#include "ContentsConst.h"

class UZone : public UObject
{
public:
	void InMsgPrint();
	void ZonePrint();

	bool InterConnecting(UZone* _LinkZone);

	bool Connecting(UZone* _LinkZone);

	bool IsConnecting(UZone* _LinkZone);

	void ConnectingPrint();

	UZone* ConnectingProgress();

	virtual UZone* InPlayer(class UPlayer& _Player)
	{
		return nullptr;
	}

protected:


private:
	UZone* LinkZone[LINKZONEMAX] = { nullptr, };
	int SelectMax = 0;
};