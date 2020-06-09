#include <iostream>
using namespace std;
void Swap(int&, int&);
int h[] = { 701,301,132,57,23,10,4,1 };
int k = 8;
void ShellSort(int a[], int n, int h[], int k)
{
	int step, i, j;
	int x, len;
	for (step = 0; step < k; step++)    // duyệt qua từng bước nhảy
	{
		len = h[step];            // chiều dài của bước nhảy
		for (i = len; i < n; i++)    // duyệt các dãy con    
		{
			// lưu phần tử cuối để tìm vị trí thích hợp trong dãy con
			x = a[i];
			// a[j] đứng trước a[i] trong cùng dãy con
			j = i - len;
			while ((x < a[j]) && (j >= 0))
				// sắp xếp dãy con chứa x dùng pp chèn
			{
				a[j + len] = a[j];    // dời về sau theo dãy con
				j = j - len;        // qua phần tử trước trong dãy con
			}
			a[j + len] = x;    // đưa x vào vị trí thích hợp trong dãy con
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
	ShellSort(a, n, h, k);
	Print(a, n);
	system("pause");
	return 0;
}