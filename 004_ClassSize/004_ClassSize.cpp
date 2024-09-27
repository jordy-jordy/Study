
#include <iostream>

class Test
{
public:
	Test()
	{

	}

	int TestValue = 10;

protected:
private:
};



int main()
{
	int ClassSize = sizeof(Test);

	Test NewTest = Test();

	__int64 Address = reinterpret_cast<__int64>(&NewTest);
	int* ClassPtr = &NewTest.TestValue;

	
	int a = 0;


}
