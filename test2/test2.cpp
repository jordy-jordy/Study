
#include <iostream>

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

void NumberToString(char* Buffer, int BufferSize, int _Value)
{
	int Count = NumberCount(_Value);

	int MulValue = 1;
	for (int i = 0; i < Count - 1; i += 1)
	{
		MulValue *= 10;
	}

	// 자료형은 의미가 없다는 소리를 선생님이 단다.
	// 해석의 차이 입니다.
	// 8421
	// 0110
	// 위와 같은 2진수를 명시적으로 '문자'로 쓰겠다고 선언하는게
	// char Test;
	// bool* Test0 = reinterprint_cast<bool*>(&Test);

	// int Test;
	// char* Ptr = reinterprint_cast<char*>(&Test);

	// 정수 => 6
	// 문자 => 6
	// 아스키 => 7bit 

	for (int i = 0; i < Count; i += 1)
	{
		int CurValue = _Value / MulValue;
		Buffer[i] = CurValue + '0';
		_Value -= CurValue * MulValue;
		MulValue /= 10;
	}

	return;
}

const int IntMaxCount = 10;
const int ParameterInter = 8;

// 함수의 인자는 무조건 8바이트씩 떨어져 있다
int MyPrintf(const char* const _Ptr, ...)
{
	__int64 FAdd = reinterpret_cast<__int64>(&_Ptr);

	int ChCount = 0;

	while (_Ptr[ChCount])
	{
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
	MyPrintf("Number : %d\n", 545454);

	int a = 0;


}

