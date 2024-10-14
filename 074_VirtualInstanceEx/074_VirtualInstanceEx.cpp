
#include <iostream>

class AActor
{
public:
	virtual ~AActor()
	{

	}
};

class Monster : public AActor
{
};

class Player : public AActor
{
};


AActor** AllActorList = nullptr;
int AllActorSize = 0;

void SpawnActor(AActor* _Actor)
{
	AllActorList = new AActor*[AllActorSize + 1];
	AllActorList[AllActorSize] = _Actor;
	++AllActorSize;
}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	for (size_t i = 0; i < AllActorSize; i++)
	{
		delete AllActorList[i];
	}

	delete[] AllActorList;


	SpawnActor(new Player());
	SpawnActor(new Player());





}
