﻿#include <iostream>
using namespace std;
void Swap(int&, int&);

void InsertionSort(int *a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int pos = i - 1;
		int x = a[i];
		while (pos >= 0 && a[pos] > x)
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void Print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "  " << a[i];
	}
	cout << endl;
}

int main()
{
	int *a = new int[10]{ 1,5,7,2,3,4,8,23,43,12 };
	int n = 10;
	Print(a, n);
	InsertionSort(a, n);
	Print(a, n);
	system("pause");
	return 0;
}