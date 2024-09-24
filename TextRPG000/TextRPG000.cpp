// TextRpg000.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>


const int LINECOUNT = 50;
const int NAMELEN = 10;

// 절차지향 
// 어떠한 현실적인 개념을 컴퓨터 세계로 끌고 들어온다.
// 상태와 
int PlayerAtt = 0;
int PlayerHp = 0;
int PlayerSpeed = 0;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 0;
int MonsterHp = 0;
int MonsterSpeed = 0;
char MonsterName[NAMELEN] = "NONE";

// 아주 중요한
void StrCopy(char* _Arr, int _BufferSize, const char* const _Name)
{
    for (int i = 0; i < _BufferSize; i += 1)
    {
        _Arr[i] = 0;
    }

    // C스타일 글자 개수 세어주는 함수
    int Size = strlen(_Name);

    // _Name의 첫번째(문자)를 _Arr의 첫번째(문자)에 붙여넣기
    // _Arr[0] = _Name[0];
    // strcpy_s()
    // 만약 _Name이 12345인 경우, Size는 5이므로 for 문은 i가 4까지만 진행됨
    for (int i = 0; i < Size; i++) 
    {
        _Arr[i] = _Name[i];
    }
}

// 함수는 그냥 자기가 만들고 싶으면 만드는 것이다.
// 전 많이 만들수록 좋아합니다.

// 행동
void CreatePlayer(const char* const _Ptr, int _Att, int _Hp, int _Speed)
{
    // char[100] = 300번지
    StrCopy(PlayerName, NAMELEN, _Ptr);
    PlayerAtt = _Att;
    PlayerHp = _Hp;
    PlayerSpeed = _Speed;
}

// 모든 문법은 코드를 덜치기 위해서 발전해왔습니다.
void CreateMonster(const char* const _Ptr, int _Att, int _Hp, int _Speed)
{
    StrCopy(MonsterName, NAMELEN, _Ptr);
    MonsterAtt = _Att;
    MonsterHp = _Hp;
    MonsterSpeed = _Speed;
}

void StatusRender(const char* _Name, int _Att, int _HP)
{
    // 내가 얻어야 하는 값 == LINECOUNT - ("_Name" 길이 + "Status " 길이)
    // A = LINECOUNT - (N + S)
    int N_len = strlen(_Name);
    int S_len = strlen("STATUS ");
    int Length = LINECOUNT - (N_len + S_len);
    printf_s("%s Status ", _Name);
    for (int i = 0; i < Length - 1; i++)
    {
        printf_s("-");
    }
    printf_s("\n");

    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _HP);

    for (int i = 0; i < LINECOUNT; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");
    // printf_s("---------------------------------------------------\n");
}



void DamageProcess(int& _DefHp, int _Att)
{
    // 게임 로직
    _DefHp -= _Att;
}

// 클래스의 필요성
// 함수는 다양한 상황에서 쓸수있게 만들수록 좋다.
// 함수는 작은 기능을 많이 만들고 
// 함수는 한번에 1가지 일을 할수록 좋다.
void Damage(const char* const _AttName, const char* const _DefName, int _Att)
{
    // 랜더링
    printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, _DefName, _Att);
}

void PlayerStatusRender()
{
    StatusRender(PlayerName, PlayerAtt, PlayerHp);
}

void MonsterStatusRender()
{
    StatusRender(MonsterName, MonsterAtt, MonsterHp);
}

void SpeedCheckRender(const char* const _Name)
{
    printf_s("%s 의 선공입니다\n", _Name);
}

int CalSpeed(int _Speed)
{
    return rand() % _Speed;
}



int main()
{
    char Arr0[5] = {1, 2, 3, 4, 5};
    char Arr1[5] = {};
    Arr1[0] = Arr0[0];
    Arr1[1] = Arr0[1];
    Arr1[2] = Arr0[2];
    Arr1[3] = Arr0[3];
    Arr1[4] = Arr0[4];
    // 글자는 기본적으로 배열
    // 배열을 다른 배열에 복사 붙여넣기 하고 싶을땐 한칸(데이터단위) 한칸 직접 복사 붙여넣기 한다는 느낌으로 진행해야 함
    // 



    // char Test0[100] = "Player";
    /*char Test1[50] = Test0;
    Test1 = Test0*/

    srand(time(0));
    CreatePlayer("AAAAAAAAAA", 10, 100, 10);
    CreateMonster("Monster1", 10, 100, 10);

    PlayerStatusRender();
    MonsterStatusRender();

    while (true)
    {
        int CurPlayerSpeed = CalSpeed(PlayerSpeed);
        int CurMonsterSpeed = CalSpeed(MonsterSpeed);

        // 화면 전체를 지워라.
        // 콘솔창에 다른 프로그램를 실행해주는 프로그램
        system("cls");
        char Input = ' ';

        PlayerStatusRender();
        MonsterStatusRender();
        Input = _getch();

        system("cls");
        // 데미지 주고
        // 플레이어가 몬스터보다 빠르다면
        // 플레이어가 먼저 데미지를 준다.
        if (CurPlayerSpeed > CurMonsterSpeed)
        {
            DamageProcess(MonsterHp, PlayerAtt);
            PlayerStatusRender();
            MonsterStatusRender();
            SpeedCheckRender(PlayerName);
            Damage(PlayerName, MonsterName, PlayerAtt);
            Input = _getch();

            system("cls");
            DamageProcess(PlayerHp, MonsterAtt);
            PlayerStatusRender();
            MonsterStatusRender();
            printf_s("%s 가 공격합니다.\n", MonsterName);
            Damage(PlayerName, MonsterName, PlayerAtt);
            Damage(MonsterName, PlayerName, MonsterAtt);
            Input = _getch();
        }
        else {
            DamageProcess(PlayerHp, MonsterAtt);
            PlayerStatusRender();
            MonsterStatusRender();
            SpeedCheckRender(MonsterName);
            Damage(MonsterName, PlayerName, MonsterAtt);
            Input = _getch();

            system("cls");
            DamageProcess(MonsterHp, PlayerAtt);
            PlayerStatusRender();
            MonsterStatusRender();
            printf_s("%s 가 공격합니다.\n", PlayerName);
            Damage(MonsterName, PlayerName, MonsterAtt);
            Damage(PlayerName, MonsterName, PlayerAtt);
            Input = _getch();
        }

        //DamageProcess(MonsterHp, PlayerAtt);
        //PlayerStatusRender();
        //MonsterStatusRender();
        //Damage(PlayerName, MonsterName, MonsterHp, PlayerAtt);
        //Input = _getch();

        //system("cls");
        //DamageProcess(PlayerHp, MonsterAtt);
        //PlayerStatusRender();
        //MonsterStatusRender();
        //Damage(PlayerName, MonsterName, MonsterHp, PlayerAtt);
        //Damage(MonsterName, PlayerName, PlayerHp, MonsterAtt);
        //Input = _getch();


        //int SpeedTest = 10;
        //int ResultSpeed = rand() % SpeedTest;

        //return 0;

        int Arr = 0;





    }

    int a = 0;



}
