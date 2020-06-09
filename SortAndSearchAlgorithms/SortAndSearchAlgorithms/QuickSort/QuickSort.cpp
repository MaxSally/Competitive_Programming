#include <iostream>
using namespace std;
void Swap(int&, int&);
void quickSort(int *a, int l, int r)
{
	
	int key = a[(l+r)/2];  //lay khoa la gia tri ngau nhien tu a[l] -> a[r]
											//int key = a[(l+r)/2];
	int i = l, j = r;

	while (i <= j)
	{
		//phepsosanh += 2; 
		while (a[i] < key) i++;       // tim phan tu ben trai ma >=key
		while (a[j] > key) j--;       // tim phan tu ben trai ma <=key
		if (i <= j)
		{
			if (i < j)
				swap(a[i], a[j]);  // doi cho 2 phan tu kieu int a[i], a[j].
			i++;
			j--;
			//phepgan += 3;
		}
	}
	//bay gio ta co 1 mang : a[l]....a[j]..a[i]...a[r]
	if (l < j) quickSort(a, l, j);   // lam lai voi mang a[l]....a[j]
	if (i < r) quickSort(a, i, r); // lam lai voi mang a[i]....a[r]
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
	quickSort(a, 0, n - 1);
	
	Print(a, n);
	system("pause");
	return 0;
}