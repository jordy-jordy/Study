#include "Objects.h"


void UObjects::SetName(const char* const _Name)
{
    if (MaxNameLen <= strlen(_Name))
    {
        MSGASSERT("�̸��� �ʹ� ��ϴ�.");
        return;
    }

    strcpy_s(Name, _Name);
}
