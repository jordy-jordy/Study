
#include <iostream>


class Example 
{
private:
    int x;
    int y;

public:
    Example(int a, int b) 
    : x(a), y(b) 
    {  // 이니셜라이저 리스트로 x, y 초기화
       // 생성자 본문은 비어있음
    }
};

class ConstantExample 
{
private:
    const int constantValue;
    int& referenceValue;

public:
    ConstantExample(int val, int& ref)
    : constantValue(val), referenceValue(ref) 
    {  // 이니셜라이저 리스트로 초기화 필수
       // 생성자 본문은 비어있음
    }
};

class Base 
{
protected:
    int baseValue;

public:
    Base(int val) 
    : baseValue(val) 
    {}
};

class Derived : public Base 
{
private:
    int derivedValue;

public:
    Derived(int baseVal, int derivedVal)
    : Base(baseVal), derivedValue(derivedVal) 
    {  // Base의 생성자 호출 및 derivedValue 초기화
       // 생성자 본문은 비어있음
    }
};



int main()
{
    {
        Example(3, 2);
    }

    {
        int TestRef = 100;
        ConstantExample(3, TestRef);
    }
  
    {
        Derived(3,2);
    }


    int a = 0;


}

