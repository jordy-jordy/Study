
#include <iostream>

int main()
{
	const char* Name0[4] = { "안녕하세요" , "테스트1", "테스트2", "테스트3"};
	const char* Name1[4] = { nullptr , };
	Name1[0] = Name0[0];
	Name1[1] = Name0[1];
	Name1[2] = Name0[2];
	Name1[3] = Name0[3];


	int a = 0;
}

