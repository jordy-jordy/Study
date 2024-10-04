#pragma once
class StatusBase
{
public:
	int GetHP(int _HP)
	{
		HP = _HP;
	}
	int GetHP(int _MP)
	{
		MP = _MP;
	}
	int GetHP(int _ATT)
	{
		ATT = _ATT;
	}
	int GetHP(int _DEF)
	{
		DEF = _DEF;
	}
	int GetHP(int _SPEED)
	{
		SPEED = _SPEED;
	}

protected:
private:
	int HP = 0;
	int MP = 0;
	int ATT = 0;
	int DEF = 0;
	int SPEED = 0;
};

