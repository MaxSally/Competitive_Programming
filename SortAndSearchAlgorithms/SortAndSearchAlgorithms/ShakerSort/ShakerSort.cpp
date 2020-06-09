#include <iostream>
using namespace std;
void Swap(int&, int&);

void ShakerSort(int *a, int n)
{
	int l, r, k;
	int j;
	l = 0; r = n - 1;
	j = r;
	while (l < r)
	{
		j = r;
		while (j > l)
		{
			if (a[j] < a[j - 1])
			{
				Swap(a[j], a[j - 1]);
				k = j;
			}
			j--;
		}
		l = k;
		j = l;
		while (j < r)
		{
			if (a[j] > a[j + 1])
			{
				Swap(a[j], a[j + 1]);
				k = j;
			}
			j++;
		}
		r = k;
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
	ShakerSort(a, n);
	Print(a, n);
	system("pause");
	return 0;
}