﻿
#include <iostream>

const int IntMaxCount = 10;
const int ParameterInter = 8;

int NumberCount(int _Value)
{
	int Result = 0;
	while (_Value)
	{
		_Value /= 10;
		Result += 1;
	}
	return Result;
}

//	 NumberToString(Arr[10],      IntMaxCount(==10), ConvertValue);
void NumberToString(char* Buffer, int BufferSize, int _Value)
{
	int Count = NumberCount(_Value);

	int MulValue = 1;
	for (int i = 0; i < Count - 1; i += 1)
	{
		MulValue *= 10;
	}

	for (int i = 0; i < Count; i += 1)
	{
		int CurValue = _Value / MulValue;
		Buffer[i] = CurValue + '0';
		_Value -= CurValue * MulValue;
		MulValue /= 10;
	}

	return;
}


// 함수의 인자는 무조건 8 바이트씩 떨어져 있다.
int MyPrintf(const char* const _Ptr, ...)
{
	// 첫번째 인자 _Ptr의 주소를 __int64형 FAdd에 대입하면서 초기화
	// &_Ptr 주소를 정수 __int64로 강제 캐스팅 하는 이유
	// 첫번째 인자인 _Ptr의 주소를 정확하게 받기 위하여
	__int64 FAdd = reinterpret_cast<__int64>(&_Ptr);

	// int형 변수 ChCount 선언 및 초기화
	// 문자열에서 n번째 (==문자열[n])
	int ChCount = 0;

	// _Ptr[ChCount]가 True일 동안 계속 진행 (False면 끝)
	// _Ptr == "Number : %d\n"
	// [ChCount] == 0
	while (_Ptr[ChCount])
	{
		// char형 변수 Ch 선언 및 _Ptr[ChCount] 값 대입
		// _Ptr == "Number : %d\n"
		// [ChCount] == 0
		char Ch = _Ptr[ChCount];

		// 만약 문자가 '%'인 경우 실행된다.
		// '%'를 넣는 이유는 Number : %d <= 이거 때문에
		if (Ch == '%')
		{
			// Ch = "Number : %d\n"[ChCount + 1]
			Ch = _Ptr[ChCount + 1];


			switch (Ch)
			{
				// & 다음에 오는 문자가 d인 경우
			case 'd':
			{
				// %d를 그대로 출력하는 것을 방지하기 위해 건너뜀
				// 문자는 기본적으로 끝을 알리는 '0'이 함께 들어가 있기 때문에
				// '문자'+'0' 까지 세어야 한다. 
				// 즉 '%d'는 보이기로는 2글자지만, 실제로는 3글자이다.
				ChCount += 2;

				// 포인터 Ptr 선언
				// FAdd 값(== 첫번째 인자의 주소)을 강제 포인터 캐스팅
				// 이는 즉 첫번째 인자 주소에 접근하겠다는 의미
				// 그리고 ParameterInter 값(==8) 만큼 이동 후 다시 대입
					// 8을 더하는 이유 == 다음 인자로 이동하기 위해!
				int* Ptr = reinterpret_cast<int*>(FAdd += ParameterInter);

				// 다음 인자에 있는 값을 ConvertValue에 대입
				int ConvertValue = *Ptr;

				// 문자열 Arr 선언
				// IntMaxCount == 10
				// 즉 Arr[10] == 메모리 공간 10개를 붙여서 준비하라는 뜻
				char Arr[IntMaxCount] = {};

				// NumberToString 함수 호출
				// 차례로 Arr, 10, ConvertValue 넣음
				// 숫자를 문자열로 바꾸는 함수
				NumberToString(Arr, IntMaxCount, ConvertValue);

				// 다음 인자인 545454를 함수 MyPrintf에 다시 대입
				// 함수 내에서 다시 같은 함수를 호출한다고 하여 재귀 함수라고 한다.
				MyPrintf(Arr);

				// case 종료
				break;
			}
			// switch의 else 같은 것
			default:

			// if로 다시 빠져나감
				break;
			}
		// if 종료
		}
		// putchar == 한글자씩 출력
		putchar(_Ptr[ChCount]);

		// [n번째에서 + 1]
		// "ABCD"[2] = "C"
		// "ABCD"[2+1] == "ABCD"[3] = "D"
		ChCount += 1;
	}

	// 
	return ChCount;
}




int main()
{

	MyPrintf("Number : %d\n", 545454);

	// 문자열 자체가 주소처럼 된다
	// 때문에 [2]를 쓰면 세번째에 있는 C가 test에 대입된다.
	char test = "ABCD"[2];

	return 0;



	int a = 0;


}

