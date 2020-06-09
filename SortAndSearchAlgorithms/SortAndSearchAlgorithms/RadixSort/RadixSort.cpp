#include <iostream>
int B[1000];
using namespace std;
void Print(int *a, int n);
void Swap(int&, int&);
void RadixSort(int *A, int n)
{
	int i, m = A[0], exp = 1;
	//int *B = new int[n];
	for (i = 0; i < n; i++)
	{
		if (A[i] > m)
			m = A[i]; // Tìm giá trị lớn nhất
	}

	while (m / exp > 0)
	{
		int bucket[10] = { 0 };// Khởi tạo các lô từ 0 đến 9
		for (i = 0; i < n; i++)
			bucket[A[i] / exp % 10]++; // Cộng từ phần đơn vị trở về trước bỏ số lần xuất hiện vào lô
		for (i = 1; i < 10; i++)
		{
			bucket[i] += bucket[i - 1];
		}
		for (i = n - 1; i >= 0; i--)
		{
			B[--bucket[A[i] / exp % 10]] = A[i];
		}
		for (i = 0; i < n; i++)
		{
			A[i] = B[i];
		}
		Print(A, n);
		exp *= 10;
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
	int a[7]={ 205,109,820,923,26,51,362};
	int n = 7;
	Print(a, n);
	RadixSort(a, n);
	Print(a, n);
	system("pause");
	return 0;
}