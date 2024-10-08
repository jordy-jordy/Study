#pragma once
#include "Objects.h"

class UStatusBase : public UObjects
{
public:
	void SetHP(int _HP)
	{
		HP = _HP;
	}
	void SetMP(int _MP)
	{
		MP = _MP;
	}
	void SetMinATT(int _MinATT)
	{
		MinATT = _MinATT;
	}
	void SetMaxATT(int _MaxATT)
	{
		MaxATT = _MaxATT;
	}
	void SetDEF(int _DEF)
	{
		DEF = _DEF;
	}
	void SetSPEED(int _SPEED)
	{
		SPEED = _SPEED;
	}

	int GetHP()
	{
		return HP;
	}
	int GetMP()
	{
		return MP;
	}
	int GetMinATT()
	{
		return MinATT;
	}
	int GetMaxATT()
	{
		return MaxATT;
	}
	int GetDEF()
	{
		return DEF;
	}
	int GetSPEED()
	{
		return SPEED;
	}
		

protected:
private:
	int HP = 0;
	int MP = 0;
	int ATT = 0;
	int MinATT = 0;
	int MaxATT = 0;
	int DEF = 0;
	int SPEED = 0;
};

