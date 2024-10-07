#pragma once
#include "StatusUnit.h"
#include "ContentsConst.h"

class UZone : public UObject
{
public:
	void InMsgPrint();


	bool InterConnecting(UZone* _LinkZone);
	bool Connecting(UZone* _LinkZone);
	bool IsConnecting(UZone* _LinkZone);


protected:


private:
	UZone* LinkZone[LINKZONEMAX] = { nullptr, };
};