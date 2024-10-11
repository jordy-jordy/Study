// 070_NewTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    "&&**";
    "&&**";
    "****";
    "****";

    int ImageScaleY = 4;
    char** AllImagePixel = new char* [ImageScaleY] {0, };
    char* Arr[4];

    int ImageScaleX = 4;
    AllImagePixel[0] = new char[ImageScaleX + 1];
    AllImagePixel[1] = new char[ImageScaleX + 1];
    AllImagePixel[2] = new char[ImageScaleX + 1];
    AllImagePixel[3] = new char[ImageScaleX + 1];

    if (nullptr != AllImagePixel)
    {
        delete[] AllImagePixel[0];
        delete[] AllImagePixel[1];
        delete[] AllImagePixel[2];
        delete[] AllImagePixel[3];
        delete[] AllImagePixel;
        AllImagePixel = nullptr;
    }
}
