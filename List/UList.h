#pragma once


typedef int DataType;

class UList
{
public:
	class UListNode
	{

	public:
		UListNode* Prev = nullptr;
		UListNode* Next = nullptr;
		DataType Data;
	};

public:
	class iterator
	{
	public:
	private:
		UListNode* CurNode;
	};

public:
	UList()
	{
		Start = new UListNode();
		End = new UListNode();
		Start->Data = -1;
		End->Data = -1;

		Start->Next = End;
		End->Prev = Start;
	}

	~UList()
	{

	}

	void push_front(const DataType& _Data)
	{
		UListNode* ListNode = new UListNode();
		ListNode->Data = _Data;

		ListNode->Prev = Start;
		ListNode->Next = Start->Next;

		Start->Next->Prev = ListNode;
		Start->Next = ListNode;
	}

	void push_back(const DataType& _Data)
	{
		UListNode* ListNode = new UListNode();
		ListNode->Data = _Data;

		ListNode->Next = End;
		ListNode->Prev = End->Prev;

		End->Prev->Next = ListNode;
		End->Prev = ListNode;

	}


private:
	UListNode* Start = nullptr;
	UListNode* End = nullptr;

};

