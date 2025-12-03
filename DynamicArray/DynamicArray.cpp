#include "DynamicArray.h"
#include<Windows.h>

DynamicArray::DynamicArray() :ptr(nullptr), size(0)
{}
DynamicArray::DynamicArray(int S)
{
	cout << "Construct by 1 param\n";
	size = S;
	ptr = new int[S];
}

DynamicArray::DynamicArray(const DynamicArray& a)// copy constructor
{
	cout << "Copy construct\n";
	size = a.size;
	ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = a.ptr[i];
	}
}
DynamicArray::~DynamicArray()
{
	cout << "Destruct\n";
	delete[] ptr;


}
void DynamicArray::Input()
{
	for (int i = 0; i < size; i++)
	{
		ptr[i] = rand() % 20;
	}
}
void DynamicArray::Output() const
{
	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << "\t";
	}
	cout << endl;
	for (size_t i = 0; i < 7 * size; i++)
	{
		cout << "-";
	}
	cout << endl;
}
int* DynamicArray::GetPointer() const
{
	return ptr;
}
int DynamicArray::GetSize() const
{
	return size;
}

void DynamicArray::ReSize(int N)
{
	if (N == size || N < 0 || N == 0) return;
	int* new_ptr = new int[N];

	int limit = (N < size ? N : size);

	for (int i = 0; i < limit; i++)
		new_ptr[i] = ptr[i];

	for (int i = limit; i < N; i++)
		new_ptr[i] = 0;

	delete[] ptr;
	ptr = new_ptr;
	size = N;
}

void DynamicArray::Sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (ptr[j] > ptr[j + 1])
			{
				int temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
			}
		}
	}
}

int DynamicArray::Search(int a) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (ptr[i] == a)
		{
			return i;
		}
	}
	return -1;
}

void DynamicArray::Reverse()
{
	int i = 0;
	int j = size - 1;
	while (i < j)
	{
		int temp = ptr[i];
		ptr[i] = ptr[j];
		ptr[j] = temp;
		i++;
		j--;
	}
}

DynamicArray DynamicArray::operator+(int)
{
	DynamicArray temp(size + 10);

	for (int i = 0; i < size; i++)
		temp.ptr[i] = this->ptr[i];

	for (int i = size; i < size + 10; i++)
		temp.ptr[i] = 0;

	return temp;
}

DynamicArray DynamicArray::operator-(int)
{
	if (size > 2)
	{
		DynamicArray temp(size - 2);

		for (int i = 0; i < temp.size; i++)
			temp.ptr[i] = this->ptr[i];
		return temp;
	}
	return *this;
}

DynamicArray DynamicArray::operator-(const DynamicArray& b)
{
	int minSize = min(size, b.size);

	DynamicArray temp(minSize);

	for (int i = 0; i < minSize; i++)
		temp.ptr[i] = this->ptr[i] - b.ptr[i];

	return temp;
}


DynamicArray DynamicArray::operator*(int)
{
	DynamicArray temp(size);

	for (int i = 0; i < size; i++)
		temp.ptr[i] = this->ptr[i] * 2;

	return temp;
}

DynamicArray DynamicArray::operator+(const DynamicArray& b)
{
	int minSize = min(size, b.size);

	DynamicArray temp(minSize);

	for (int i = 0; i < minSize; i++)
		temp.ptr[i] = this->ptr[i] + b.ptr[i];

	return temp;
}

DynamicArray DynamicArray::operator--()
{
	for (int i = 0; i < size; i++)
		ptr[i]--;

	return *this; 
}

DynamicArray DynamicArray::operator++()
{
	for (int i = 0; i < size; i++)
		ptr[i]++;

	return *this; 
}
