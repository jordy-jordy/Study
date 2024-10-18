#pragma once
#include <iostream>


typedef int KeyType;
typedef int ValueType;

class UPair
{
public:
	KeyType first;
	ValueType second;
};

UPair Umake_pair(const KeyType& _Key, const ValueType& _Value);

class less
{
public:
	bool operator()(int _left, int _Right)
	{
		return _left > _Right;
	}
};


class UMap
{
private:
	class UMapNode
	{
	public:
		UMapNode* Parent = nullptr;
		UMapNode* LeftChild = nullptr;
		UMapNode* RightChild = nullptr;
		UPair Pair;

		void FirstOrder()
		{
			std::cout << Pair.first << std::endl;
			if (nullptr != this->LeftChild)
			{
				LeftChild->FirstOrder();
			}
			if (nullptr != this->RightChild)
			{
				RightChild->FirstOrder();
			}
		}
		void MidOrder()
		{
			if (nullptr != LeftChild)
			{
				LeftChild->MidOrder();
			}
			std::cout << Pair.first << std::endl;
			if (nullptr != RightChild)
			{
				RightChild->MidOrder();
			}
		}
		void LastOrder()
		{
			if (nullptr != LeftChild)
			{
				LeftChild->LastOrder();
			}
			if (nullptr != RightChild)
			{
				RightChild->LastOrder();
			}

			// 각 노드를 돌며 삭제
			delete this;
			
		}

		void ChildRelease(UMapNode* _Node)
		{

			if (LeftChild == _Node)
			{
				LeftChild = nullptr;
				return;
			}

			if (RightChild == _Node)
			{
				RightChild = nullptr;
				return;
			}
		}

		UMapNode* OverParent(const KeyType& _Key)
		{
			if (nullptr != Parent)
			{
				if (Parent->Pair.first > _Key)
				{
					return Parent;
				}

				return Parent->OverParent(_Key);
			}

			return nullptr;
		}

		UMapNode* NextNode()
		{
			if (nullptr == RightChild)
			{
				return OverParent(Pair.first);
			}

			return RightChild->MinNode();
		}

		UMapNode* MinNode()
		{
			if (nullptr == LeftChild)
			{
				return this;
			}

			return LeftChild->MinNode();
		}

		UMapNode* MaxNode()
		{
			if (nullptr == RightChild)
			{
				return this;
			}

			return RightChild->MaxNode();
		}

		UMapNode* FindNode(const KeyType& _Key)
		{
			if (this->Pair.first == _Key)
			{
				return this;
			}

			if (Pair.first > _Key)
			{
				return LeftChild->FindNode(_Key);
			}
			else
			{
				return RightChild->FindNode(_Key);
			}

			return nullptr;
		}

		void insertNode(const UPair& _Pair)
		{
			if (Pair.first == _Pair.first)
			{
				return;
			}


			less NewLess;

			if (NewLess(Pair.first, _Pair.first))
			{
				if (nullptr == LeftChild)
				{
					LeftChild = new UMapNode();
					LeftChild->Parent = this;
					LeftChild->Pair = _Pair;
					return;
				}

				LeftChild->insertNode(_Pair);
			}
			else
			{
				if (nullptr == RightChild)
				{
					RightChild = new UMapNode();
					RightChild->Parent = this;
					RightChild->Pair = _Pair;
					return;
				}

				RightChild->insertNode(_Pair);

			}

		}
	};

public:
	class iterator
	{
		friend UMap;
	public:
		iterator& operator++()
		{
			CurNode = CurNode->NextNode();
			return *this;
		}


		bool operator!=(const iterator& _Other)
		{
			return CurNode != _Other.CurNode;
		}

		UPair* operator->()
		{
			return &CurNode->Pair;
		}

		iterator(UMapNode* _Node)
			: CurNode(_Node)
		{

		}

	private:
		UMapNode* CurNode = nullptr;
	};



public:
	iterator begin()
	{
		if (nullptr == Root)
		{
			return iterator(nullptr);
		}

		return iterator(Root->MinNode());
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	iterator Find(const KeyType& _Key)
	{
		if (nullptr == Root)
		{
			return nullptr;
		}

		UMapNode* Node = Root->FindNode(_Key);
		return iterator(Node);
	}

	iterator erase(iterator& _iter)
	{
		iterator Return = _iter.CurNode->NextNode();
		UMapNode* CurNode = _iter.CurNode;
		UMapNode* Parent = _iter.CurNode->Parent;

		if (nullptr == CurNode->LeftChild &&
			nullptr == CurNode->RightChild)
		{
			if (nullptr == Parent)
			{
				Root = nullptr;
			}

			Parent->ChildRelease(CurNode);

			delete CurNode;
			CurNode = nullptr;
			return Return;
		}

		if (nullptr != CurNode->LeftChild ||
			nullptr != CurNode->RightChild)
		{
			UMapNode* ChangeNode = nullptr;

			if (nullptr != CurNode->LeftChild)
			{
				ChangeNode = CurNode->LeftChild->MaxNode();
			}
			else
			{
				ChangeNode = CurNode->RightChild->MinNode();
			}

			if (nullptr != ChangeNode->Parent)
			{
				ChangeNode->Parent->ChildRelease(ChangeNode);
			}

			UMapNode* CurLeftChild = CurNode->LeftChild;
			UMapNode* CurRightChild = CurNode->RightChild;

			if (nullptr != CurLeftChild)
			{
				CurLeftChild->Parent = nullptr;
			}

			if (nullptr != CurRightChild)
			{
				CurRightChild->Parent = nullptr;
			}


			if (nullptr != CurLeftChild)
			{
				if (CurLeftChild != ChangeNode)
				{
					CurLeftChild->Parent = ChangeNode;
					ChangeNode->LeftChild = CurLeftChild;
				}
			}

			if (nullptr != CurRightChild)
			{
				if (CurRightChild != ChangeNode)
				{
					CurRightChild->Parent = ChangeNode;
					ChangeNode->RightChild = CurRightChild;
				}
			}

			ChangeNode->Parent = CurNode->Parent;

			UMapNode* ParentNode = CurNode->Parent;

			if (nullptr != ParentNode)
			{
				if (ParentNode->RightChild == CurNode)
				{
					ParentNode->RightChild = ChangeNode;
				}
				else
				{
					ParentNode->LeftChild = ChangeNode;
				}
			}

			if (Root == CurNode)
			{
				Root = ChangeNode;
			}

			delete CurNode;
			CurNode = nullptr;
			return Return;
		}

		return nullptr;
	}

	void FirstOrder()
	{
		std::cout << "전위 순회" << std::endl;
		Root->FirstOrder();
		std::cout << std::endl;
	}
	void MidOrder()
	{
		std::cout << "중위 순회" << std::endl;
		Root->MidOrder();
		std::cout << std::endl;
	}
	void LastOrder()
	{
		std::cout << "후위 순회" << std::endl;
		Root->LastOrder();
		std::cout << std::endl;
	}

	void insert(const UPair& _Pair)
	{
		if (nullptr == Root)
		{
			Root = new UMapNode();
			Root->Pair = _Pair;
			return;
		}

		if (true == isRotate())
		{
			Rotate();
		}

		Root->insertNode(_Pair);
	}


	~UMap()
	{
		// 소멸자 호출하면 라스트 오더 호출
		Root->LastOrder();
	}

public:
	UMapNode* Root = nullptr;

	bool isRotate()
	{
		return false;
	}

	void Rotate()
	{
		if (true)
		{
			LeftRotate();
		}

		if (true)
		{
			RightRotate();
		}

		return;
	}

	void LeftRotate() {}

	void RightRotate() {}
};

