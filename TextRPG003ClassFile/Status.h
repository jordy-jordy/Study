#pragma once
class Status
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
	void SetSPEED(int _Speed)
	{
		SPEED = _Speed;
	}
	void SetATT(int _Att)
	{
		ATT = _Att;
	}
	void SetDEF(int _Def)
	{
		DEF = _Def;
	}

protected:

private:
	int HP;
	int MP;
	int SPEED;
	int ATT;
	int DEF;

};

