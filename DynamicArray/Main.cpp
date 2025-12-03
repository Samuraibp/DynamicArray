#include "DynamicArray.h"
#include <iostream>
using namespace std;



DynamicArray GetObj() //возврат по значению
{
	DynamicArray obj(3);
	obj.Input();

	return obj;
}
int main()
{
	DynamicArray a(5); // constructor 1 param
	a.Input();
	a.Output();
	DynamicArray b = a; // copy constructor
	b.Output();

	DynamicArray rezult = GetObj();

	b.ReSize(7);
	b.Output();
	cout << endl;

	b.Sort();
	b.Output();
	cout << endl;
	

	int rez = b.Search(55);
	if (rez != -1)
	{
		cout << "Found at index " << rez << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}
	cout << endl;
	cout << endl;
		

	b.Reverse();
	b.Output();
	cout << endl;

	DynamicArray c = b + 10;
	c.Output();

	DynamicArray x = c - 2;
	x.Output();

	DynamicArray y = x * 2;
	y.Output();

	DynamicArray t = y - x;
	t.Output();

	DynamicArray e = y + x;
	e.Output();

	++e;
	e.Output();

	--e;
	e.Output();


	system("pause");
}