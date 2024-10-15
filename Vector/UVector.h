#pragma once
#include <assert.h>



template<typename DataType>
class UVector
{
public:
	~UVector()
	{
		if (nullptr != Datas)
		{
			delete[] Datas;
			Datas = nullptr;
		}
	}

	void reserve(size_t _capacity)
	{
		if (CapacityValue > _capacity)
		{
			return;
		}

		DataType* PrevData = Datas;

		Datas = new DataType[_capacity];

		if (nullptr != PrevData)
		{
			for (size_t i = 0; i < SizeValue; i++)
			{
				Datas[i] = PrevData[i];
			}

			delete[] PrevData;
			PrevData = nullptr;
		}
		CapacityValue = _capacity;
	}

	size_t capacity() const
	{
		return CapacityValue;
	}

	size_t size() const
	{
		return SizeValue;
	}

	void clear()
	{
		SizeValue = 0;
	}

	void push_back(DataType _Data)
	{
		if (SizeValue + 1 > CapacityValue)
		{
			reserve(CapacityValue * 1.5);
		}


		Datas[SizeValue] = _Data;

		++SizeValue;
	}

	DataType& operator[](size_t _index)
	{
		if (SizeValue <= _index)
		{
			assert(false);
		}

		return Datas[_index];
	}


private:
	DataType* Datas = nullptr;
	size_t CapacityValue = 0;
	size_t SizeValue = 0;
};

