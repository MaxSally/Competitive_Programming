#include <iostream>
using namespace std;
void Swap(int&, int&);

void BInsertionSort(int a[], int n)
{
	int l, r, m, i;
	int x;//lưu giá trị a[i] tránh bị ghi đè khi dời chỗ các phần tử.  
	for (int i = 1; i < n; i++)
	{
		x = a[i]; l = 0;
		r = i - 1;
		while (l <= r) // tìm vị trí chèn x 
		{
			m = (l + r) / 2;
			// tìm vị trí thích hợp m   
			if (x < a[m])
			{
				r = m - 1;
			}
			else l = m + 1;
		}
		for (int j = i - 1; j >= l; j--)
		{
			a[j + 1] = a[j];// dời các phần tử sẽ đứng sau x  
		}
		a[l] = x;  // chèn x vào dãy  }
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
	BInsertionSort(a, n);
	Print(a, n);
	system("pause");
	return 0;
}