// Quick Sort

int part(int a[], int l, int h)
{
	int pivot=a[h];
	int ind=l-1;
	
	for(int i=l;i<h;i++)
	{
		if(a[i]<=pivot)
		{
			ind++;
			swap(a[i],a[ind]); 
		}
	}
	swap(a[ind+1], a[h]);
	return ind+1;
	//ind+1 gives the right position of the pivot, after placing the smaller elements to left and larger to right
}

void quicksort(int a[], int l, int h)
{
	if(l<h)
	{
	int pi=part(a,l,h); 	//pi=>partitioning index, a[pi] is now at right position;
	quicksort(a,l,pi-1);
	quicksort(a,pi+1,h);	
	}
	
}



int main() {
	// your code goes here
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	quicksort(a,0,n-1);
	
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	
	return 0;
}

//
// C++ program for implementation of Heap Sort 
#include <iostream> 

using namespace std; 

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
	int largest = i; // Initialize largest as root 
	int l = 2*i + 1; // left = 2*i + 1 
	int r = 2*i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	// If largest is not root 
	if (largest != i) 
	{ 
		swap(arr[i], arr[largest]); 

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest); 
	} 
} 

// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i); 

	// One by one extract an element from heap 
	for (int i=n-1; i>0; i--) 
	{ 
		// Move current root to end 
		swap(arr[0], arr[i]); 

		// call max heapify on the reduced heap 
		heapify(arr, i, 0); 
	} 
} 

/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
	for (int i=0; i<n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 

// Driver program 
int main() 
{ 
	int arr[] = {12, 11, 13, 5, 6, 7}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	heapSort(arr, n); 

	cout << "Sorted array is \n"; 
	printArray(arr, n); 
} 
