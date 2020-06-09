#include <iostream>
using namespace std;

int LinearSearch(int *a, int n , int key)
{
	int i = 0;
	a[n] = key;
	while (a[i] != key)
	{
		i++;
	}
	if (i == n)
		return -1;
	else
		return i;
}

int main()
{
	int *a; int n; int key;
	cout << "Nhap so luong phan tu :";
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "]: ";
		cin >> a[i];
	}
	cout << "Nhap so can tim :";
	cin >> key;
	int index = LinearSearch(a, n, key);
	if (index)
		cout << key << " co trong mang va nam o vi tri a[" << index << "]" << endl;
	else
		cout << key << " khong co trong mang " << endl;
	delete []a;
	system("pause");
	return 0;
}