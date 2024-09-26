#include <iostream>

const int NAMELEN = 10;

class StatusUnit
{
protected:
    char Name[NAMELEN] = "NONE";
    int Hp = 100;
    int MinAtt = 10;
    int MaxAtt = 20;
    int Speed = 10;
    int Charm = 0;
};

class FightUnit : public StatusUnit
{
public:
    // 의견을 구해 얻은 함수
    int GetDamage00() const
    {
        int Damage0 = rand() % 11;
        return 10 + Damage0;
    }

    // 제가 처음 생각한 함수
    int GetDamage01() const
    {
        int Damage1 = rand() % (MaxAtt + 1);
        if (Damage1 < MinAtt)
        {
            Damage1 += MinAtt;
            return Damage1;
        }
        else
        {
            return Damage1;
        }
    }

    void DamageLogic00(const FightUnit& _AttUnit)
    {
        Hp -= _AttUnit.GetDamage00();
    }

    void DamageLogic01(const FightUnit& _AttUnit)
    {
        Hp -= _AttUnit.GetDamage01();
    }

    void DamageRender(const char* const _AttName, int _Att)
    {
        printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, Name, _Att);
    }

    const char* GetName() const
    {
        return Name;
    }

protected:
private:
};

class Player : public FightUnit
{
};

class Monster : public FightUnit
{
};

int main()
{
    srand(time(0));


    Player NewPlayer;
    Monster NewMonster;
    NewMonster.DamageLogic00(NewPlayer);

    int Test00 = 0;
    int Test01 = 0;
    while (true)
    {
    Test00 = NewPlayer.GetDamage00();
    Test01 = NewPlayer.GetDamage01();
    }


    int a = 0;

}

