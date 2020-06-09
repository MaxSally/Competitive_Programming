#include <iostream>
using namespace std;

int BinarySearch(int *a, int n, int key)
{
	int left = 0, right = n - 1,mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == key)
			return mid;
		else if (a[mid] > key)
			right = key;
		else
			left = key;
	}
	return -1;
}

int main()
{
	int *a; int n; int key;
	cout << "Nhap so luong phan tu co thu tu tang dan :";
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "]: ";
		cin >> a[i];
	}
	cout << "Nhap so can tim :";
	cin >> key;
	int index = BinarySearch(a, n, key);
	if (index)
		cout << key << " co trong mang va nam o vi tri a[" << index << "]" << endl;
	else
		cout << key << " khong co trong mang " << endl;
	system("pause");
	return 0;
}