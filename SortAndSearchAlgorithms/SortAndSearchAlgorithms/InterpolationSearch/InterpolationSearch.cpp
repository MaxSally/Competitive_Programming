// Tìm kiếm nội suy
// This is an improvement of BinarySearch
// This article is contributed by Aayu sachdev
/*
// The idea of formula is to return higher value of pos
// when element to be searched is closer to arr[hi]. And
// smaller value when closer to arr[lo]
pos = lo + [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo]) ]

arr[] ==> Array where elements need to be searched
x     ==> Element to be searched
lo    ==> Starting index in arr[]
hi    ==> Ending index in arr[]

*/

/*
Algorithm
Rest of the Interpolation algorithm is same except the above partition logic.

Step1: In a loop, calculate the value of “pos” using the probe position formula.
Step2: If it is a match, return the index of the item, and exit.
Step3: If the item is less than arr[pos], calculate the probe position of the left sub-array. Otherwise calculate the same in the right sub-array.
Step4: Repeat until a match is found or the sub-array reduces to zero.
*/
#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int x)
{
	// Find indexes of two corners
	int lo = 0, hi = (n - 1);

	// Since array is sorted, an element present
	// in array must be in range defined by corner
	while (lo <= hi && x >= arr[lo] && x <= arr[hi])
	{
		// Probing the position with keeping
		// uniform distribution in mind.
		int pos = lo + (((double)(hi - lo) /
			(arr[hi] - arr[lo]))*(x - arr[lo]));

		// Condition of target found
		if (arr[pos] == x)
			return pos;

		// If x is larger, x is in upper part
		if (arr[pos] < x)
			lo = pos + 1;

		// If x is smaller, x is in lower part
		else
			hi = pos - 1;
	}
	return -1;
}

int main()
{
	// Array of items on which search will
	// be conducted.
	int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21, 22, 23,
		24, 33, 35, 42, 47 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int x = 18; // Element to be searched
	int index = interpolationSearch(arr, n, x);
	// pos = =0+(15-0)/(47-10)*(18-10)
	// If element was found
	if (index != -1)
		cout << "Element found at index" << index << endl;
	else
		cout << "Element not found " << endl;
	system("pause");
	return 0;
}