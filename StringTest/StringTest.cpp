
#include <iostream>

int main()
{
	const char* Name0[16] = { "안녕하세요" , "테스트", };
	const char* Name1[16] = { nullptr , };
	Name1[0] = Name0[0];
	Name1[1] = Name0[1];
	Name1[2] = Name0[2];
	Name1[3] = Name0[3];
	Name1[4] = Name0[4];


	int a = 0;
}

