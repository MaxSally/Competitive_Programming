#include <iostream>
using namespace std;
void Swap(int&, int&);
/// nếu mảng bắt đầu từ 1 thì 2 phần tử liên đới của a[i] là a[2*i] và a[2*i+1]
/// Nếu mảng bắt đầu từ 0 thì 2 phần tử liên đới của a[i] là a[2*i + 1] và a[2*i+2]
void Shift(int *a, int l, int r)
{
	int x;
	int i = l;
	int j = 2 * i +1 ;
	x = a[i];
	while (j <= r)
	{
		if (j < r)
		{
			if (a[j] < a[j + 1])
				j++;
		}
		if (a[j] <= x)
			return;
		else
		{
			a[i] = a[j];
			a[j] = x;
			i = j;
			j = 2 * i+1;
		}
	}
}

void CreateHeap(int *a, int n)
{
	int l = n / 2 - 1;
	while (l >= 0)
	{
		Shift(a, l,n-1);
		l--;
	}
}
void HeapSort(int *a, int n)
{
	int r;
	CreateHeap(a, n);
	r = n - 1;
	while (r > 0)
	{
		Swap(a[0], a[r]);
		r--;
		if (r > 0)
			Shift(a, 0, r);
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
	int *a = new int[10]{ 9,5,7,2,3,4,8,23,43,12 };
	int n = 10;
	Print(a, n);
	HeapSort(a, n);
	Print(a, n);
	system("pause");
	return 0;
}