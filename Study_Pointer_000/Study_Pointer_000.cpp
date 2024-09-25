

#include <iostream>

int PutValue = 2;


int Number01 (int _Value0, const char* const _Value1, int _Value2, bool _Value3)
{
	__int64 Address = reinterpret_cast<__int64>(&_Value0);
	int* Ptr2 = reinterpret_cast<int*>(Address + 8*(PutValue - 1));
	int Result = *Ptr2;

	return Result;
}


int main()
{
	//				  	 1  2  3  4  5  6  7  8  9  10 11
	int Number00[11] = { 0, 1, 2, 3, 4 ,5, 6, 7, 8, 9, 10 };
	__int64 Address = reinterpret_cast<__int64>(&Number00);
	int* Ptr00 = reinterpret_cast<int*>(Address + (PutValue - 1) * sizeof(int));
	int OutNumber00 = *Ptr00;

	int OutNumber01 = Number01(10, "ABC", 30, 40);

	int a = 0;

}

