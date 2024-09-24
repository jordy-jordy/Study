
#include <iostream>

int NumberCount(int _Value)			// _Value 값을 받음
{
	int Result = 0;					// Result 선언
	while (_Value)					// _Value 가 True인 경우 진행, False인 경우 끝
	{
		_Value /= 10;				// _Value에 10을 나누고 다시 대입
		Result += 1;				// Reselt에 +1을 하고 다시 대입
	}
	return Result;
}
// _Value가 0이 될 때까지 Result에 1씩 카운트 되는 방식

void NumberToString(char* Buffer, int BufferSize, int _Value)		// Buffer의 주소값, BufferSize의 값, _Value의 값을 받음 
{
	int Count = NumberCount(_Value);		// Count 선언. NumberCount 함수 호출. 위에서 받은 _Value 인자를 사용. NumberCount의 Result 값을 Count에 대입

	int Value = 3;							// Value 선언
	char Ch = Value + '0';					// Ch 선언. Value 값에 문자 '0'을 더하고 Ch에 대입

	int CurValue = _Value / 10;				// CurValue 선언. _Value에 10을 나눈 값을 대입


	return;
}

const int IntMaxCount = 10;
const int ParameterInter = 8;

// 함수의 인자는 무조건 8바이트씩 떨어져 있다.
int MyPrintf(const char* const _Ptr, ...)					// _Ptr 포인터를 받음. 해당 포인터는 
{
	__int64 FAdd = reinterpret_cast<__int64>(&_Ptr);

	int ChCount = 0;

	while (_Ptr[ChCount])
	{
		char Ch = _Ptr[ChCount];

		if (Ch == '%')
		{
			Ch = _Ptr[ChCount + 1];

			switch (Ch)
			{
			case 'd':
			{
				int* Ptr = reinterpret_cast<int*>(FAdd += ParameterInter);
				int ConvertValue = *Ptr;
				char Arr[IntMaxCount] = {};
				NumberToString(Arr, IntMaxCount, ConvertValue);

				MyPrintf("100");
				ChCount += 2;
				break;
			}
			default:
				break;
			}
			// 함수내부에서 자기자신을 다시 호출하는 방식을 사용해볼겁니다.
			// 이걸 재귀함수라고 부릅니다.
		}

		putchar(_Ptr[ChCount]);
		ChCount += 1;
	}

	return ChCount;
}

void ReFunction()
{
	// 잘 종료를 해줘야 한다.
	if (true)
	{
		return;
	}

	ReFunction();
}

int main()
{
	// int Value = '1';

	// ReFunction();

	// 숫자를 출력하는 기능을 포맷팅이라는 것으로 만들어 놨습니다.

	// %d는 정수 출력할께요
	// printf_s("%d, %d", nullptr);
	// printf_s("Number : %d\n", 12321);

	// \n 엔터 줄바꿈 처리를 해라.
	MyPrintf("Number : %d\n", 12321);
	// MyPrintf("Number : %d\n", 333);
	// "Number : 100\n"

	int Value = 123;

	char Arr[IntMaxCount] = {};
	// 100이라는 숫자부터 시작해야한다는것은 어떻게 알수 있을까?
	// 3 = NumberCount(Value);
	Arr[0] = Value / 100;
	Arr[1] = Value / 10;
	Arr[2] = Value / 1;




	
	// 포인터는 반드시 주소 값을 받아야 한다.
	int TestPtrValue = 0;
	int* TestPtr0 = &TestPtrValue;


}
