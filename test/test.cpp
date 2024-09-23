
#include <iostream>



int main()
{
	int Arr[5] = {1, 10, 100, 1000};
	int ArrTest0 = Arr[0];
	int ArrTest1 = Arr[1];
	int ArrTest2 = Arr[2];

	const char* Text0 = "ABCD";
	char Text0_0 = Text0[0];
	char Text0_1 = Text0[1];
	char Text0_2 = Text0[2];
	char Text0_3 = Text0[3];

	const char* const Text1 = "QWER";
	char Text1_0 = Text1[0];
	char Text1_1 = Text1[1];
	char Text1_2 = Text1[2];
	char Text1_3 = Text1[3];

					  // 배열 이름이 주소가 될수 있다..
	const char* const Text2[4] = { "A","S","D","F" };
	char Text2_0 = *Text2[0];
	char Text2_1 = *Text2[1];
	char Text2_2 = *Text2[2];
	char Text2_3 = *Text2[3];
			 
	int PtrArr[5] = {10, 20, 30, 40, 50};
	int* Ptr = PtrArr;
	int AAA = Ptr[0];
	int BBB = Ptr[1];
	Ptr[3] = 100;



	int a = 0;
}

