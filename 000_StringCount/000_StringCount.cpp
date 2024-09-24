
// 1번째 숙제

#include <iostream>


int StringCount(const char* const _Str)
{
    int Count = 0;

    while (_Str[Count])
    {
        Count += 1;
    }

    return Count;
}

int main()
{
    // [B][B][B][B][0]
    int Count = strlen("BBBB");
    int Count2 = StringCount("BBBB0");



    int a = 0;
}
