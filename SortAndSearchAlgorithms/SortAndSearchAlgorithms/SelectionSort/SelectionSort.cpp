#include <iostream>
using namespace std;
void Swap(int&, int&);
void SelectionSort(int *a, int n)
{
	int i, min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
			Swap(a[min], a[i]);
		}
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
	SelectionSort(a, n);
	Print(a, n);
	system("pause");
	return 0;
}