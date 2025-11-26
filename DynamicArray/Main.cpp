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

	system("pause");
}