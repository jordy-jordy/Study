#include <iostream>

int PutValue = 0;
int Edit_Number00 = 0;
int Edit_Number01 = 0;

int ParameterLen = 8;
int SizeofInt = 4;

int Number00(const int* const _Value0)
{
	PutValue = PutValue - 1;
	int Result = 0;
	__int64 Address = reinterpret_cast<__int64>(_Value0);
	Address = Address + SizeofInt * PutValue;
	int* Ptr00 = reinterpret_cast<int*>(Address);

	if (0 < Edit_Number00)
	{
		*Ptr00 = Edit_Number00;
		Result = *Ptr00;
	}
	else
	{
		Result = *Ptr00;
		//int Result = _Value0[PutValue];
	}

	return Result;
}

int Number01 (int _Value0, const char* const _Value1, int _Value2, bool _Value3)
{
	PutValue = PutValue - 1;
	int Result = 0;
	__int64 Address = reinterpret_cast<__int64>(&_Value0);

	// 주소 확인용
	//__int64 address0 = reinterpret_cast<__int64>(&_Value0);
	//__int64 address1 = reinterpret_cast<__int64>(&_Value1);
	//__int64 address2 = reinterpret_cast<__int64>(&_Value2);
	//__int64 address3 = reinterpret_cast<__int64>(&_Value3);

	Address = Address + ParameterLen * PutValue;
	int* Ptr01 = reinterpret_cast<int*>(Address);
	Result = *Ptr01;

	return Result;
}

int Test(int _Value0, const char* const _Value1, int _Value2, bool _Value3)
{
	int TransValue2 = _Value2;
	int TransValue3 = _Value3;

	__int64 Address0 = reinterpret_cast<__int64>(&_Value0);
	__int64 Address1 = reinterpret_cast<__int64>(&_Value1);
	__int64 Address2 = reinterpret_cast<__int64>(&TransValue2);
	__int64 Address3 = reinterpret_cast<__int64>(&TransValue3);
	
	int* TestPtr0 = reinterpret_cast<int*>(Address0);
	int* TestPtr1 = reinterpret_cast<int*>(Address1);
	int* TestPtr2 = reinterpret_cast<int*>(Address2);
	int* TestPtr3 = reinterpret_cast<int*>(Address3);

	int Result0 = *TestPtr0;
	int Result1 = *TestPtr1;
	int Result2 = *TestPtr2;
	int Result3 = *TestPtr3;

	return 0;
}

int main()
{
	PutValue = 4;
	//Edit_Number00 = 0;
	//Edit_Number01 = 140;

	//int Arr00[11] = { 0, 1, 2, 3, 4 ,5, 6, 7, 8, 9, 10 };
	//int OutNumber00 = Number00(Arr00);
	int OutNumber01 = Number01(10, "ABC", 30, 40);

	//Test(10, "바보", 20, 40);



	const char* ValueChar = "ABC";
	bool ValueBool = 0;
	int ValueInt = 40;
	int BooltoInt = ValueBool;
	int ChartoInt = *ValueChar;

	int a = 0;

	}