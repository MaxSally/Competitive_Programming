#include <iostream>
#include <algorithm>
using namespace std;
// A utility function to swap two elements
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
/*
Method 1 :
int kthSmallest(int *a, int n , int k)
{
sort(a, a + n);
return a[k - 1];
}
*/

/*
Method 2: Using Max-Heap
*/
/*
class MaxHeap
{
	int *harr; // pointer to array of elements in heap
	int capacity;// maximum possible size of max heap
	int heap_size; // Current number of elements in max heap
public:
	MaxHeap(int *a, int size); // Constructor
	void maxHeapify(int i);  //To maxHeapify subtree rooted with index i
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }
	int extractMax();  // extracts root (maximum) element
	int getMax() { return harr[0]; } // Returns maximum
	// to replace root with new node x and heapify() new root
	void replaceMax(int x) { harr[0] = x;  maxHeapify(0); }
};

MaxHeap::MaxHeap(int *a, int size)
{
	heap_size = size;
	int i = (heap_size - 1) / 2;
	harr = a;
	while (i >= 0)
	{
		maxHeapify(i);
		i--;
	}
}

void MaxHeap::maxHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int largest = i;
	if (l<heap_size && harr[l] > harr[i])
		largest = l;
	if (r < heap_size && harr[r]> harr[largest])
		largest = r;
	if (largest != i)
	{
		swap(harr[i], harr[largest]);
		maxHeapify(largest);
	}
}

int MaxHeap::extractMax()
{
	if (heap_size == 0)
		return INT_MAX;

	// Store the maximum vakue.
	int root = harr[0];

	// If there are more than 1 items, move the last item to root
	// and call heapify.
	if (heap_size > 1)
	{
		harr[0] = harr[heap_size - 1];
		maxHeapify(0);
	}
	heap_size--;

	return root;
}

// Function to return k'th largest element in a given array
int kthSmallest(int arr[], int n, int k)
{
	// Build a heap of first k elements: O(k) time
	MaxHeap mh(arr, k);

	// Process remaining n-k elements.  If current element is
	// smaller than root, replace root with current element
	for (int i = k; i<n; i++)
		if (arr[i] < mh.getMax())
			mh.replaceMax(arr[i]);

	// Return root
	return mh.getMax();
}
*/

/*
Method 3 : Using Min Heap – HeapSelect*/
	class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    MinHeap(int a[], int size); // Constructor
    void MinHeapify(int i);  //To minheapify subtree rooted with index i
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }
 
    int extractMin();  // extracts root (minimum) element
    int getMin() { return harr[0]; } // Returns minimum
};
 
MinHeap::MinHeap(int a[], int size)
{
    heap_size = size;
    harr = a;  // store address of array
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}
 
// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size == 0)
        return INT_MAX;
 
    // Store the minimum vakue.
    int root = harr[0];
 
    // If there are more than 1 items, move the last item to root
    // and call heapify.
    if (heap_size > 1)
    {
        harr[0] = harr[heap_size-1];
        MinHeapify(0);
    }
    heap_size--;
 
    return root;
}
 
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
 

 
// Function to return k'th smallest element in a given array
int kthSmallest(int arr[], int n, int k)
{
    // Build a heap of n elements: O(n) time
    MinHeap mh(arr, n);
 
    // Do extract min (k-1) times
    for (int i=0; i<k-1; i++)
        mh.extractMin();
 
    // Return root
    return mh.getMin();
}
//*/


int main()
{
	int arr[] = { 12, 3, 5, 7, 19 };
	int n = sizeof(arr) / sizeof(arr[0]), k = 2;
	cout << "K'th smallest element is " << kthSmallest(arr, n, k);
	cin.get();
	return 0;
}