

#include <iostream>

int PutValue = 0;
int Edit_Number00 = 0;
int Edit_Number01 = 0;

int ParameterLen = 8;
int SizeofInt = 4;

int Number00(const int* const _Value0)
{
	PutValue -= 1;
	int Result = 0;

	if (0 < Edit_Number00)
	{

	}
	else
	{
		__int64 Address = reinterpret_cast<__int64>(_Value0);
		Address = Address + SizeofInt * PutValue;
		int* Ptr00 = reinterpret_cast<int*>(Address);
		Result = *Ptr00;
		//int Result = _Value0[PutValue];
	}


	return Result;
}


int Number01 (int _Value0, const char* const _Value1, int _Value2, bool _Value3)
{
	PutValue -= 1;
	__int64 Address = reinterpret_cast<__int64>(&_Value0);
	int* Ptr01 = reinterpret_cast<int*>(Address + ParameterLen*(PutValue));
	int Result = *Ptr01;

	return Result;
}


int main()
{
	PutValue = 3;
	Edit_Number00 = 120;
	Edit_Number01 = 140;

	int Arr00[11] = { 0, 1, 2, 3, 4 ,5, 6, 7, 8, 9, 10 };
	int OutNumber00 = Number00(Arr00);
	int OutNumber01 = Number01(10, "ABC", 30, 40);

	int a = 0;

}

