//  stable-
//  	 if two objects with equal or same keys appear in the same order in sorted output as they appear in the input array to be sorted.


//1. Quick Sort 

// best and average: O(nlogn), worst: O(n^2)
// best-> when pivot is mid element, worst-> skewed tree
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
// quicksort(a,0,n-1);


//2. Merge Sort
//(BAW): (Ω(n log(n)),θ(n log(n)), O(n log(n)))

// 2 3 4 1 5 6 9 -1 0
void merge(int l, int mid, int h, vector<int>&arr)
{
		//left array-> l to mid & right-> mid+1 to h
	vector<int> temp(h-l+1);
	
	int i = l,j = mid+1;
	int t =0;
	while(i<=mid && j<= h)
	{
		if(arr[i]<=arr[j])
		{
			temp[t++] = arr[i++];
		}
		else temp[t++] = arr[j++];
	}
	while(i<=mid)
		temp[t++] = arr[i++];
	while(j<=h)
		temp[t++] = arr[j++];
	
	t=0; //for temp array index
	for(int i=l;i<=h;i++)
		arr[i] = temp[t++];

}

void mergeSort(int l, int h, vector<int>& arr)
{
	if(l>=h)return;

	int mid = (l+h)/2;
	mergeSort(l,mid,arr);
	mergeSort(mid+1,h,arr);

	merge(l,mid,h,arr);
}
//mergeSort(0,n-1,arr)



//3. Heap Sort

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

void heapSort(int arr[], int n) 
{ 
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--) //((int)n/2) - 1 : last node in second last level
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
// heapSort(arr, n); //func call


**************
//4. BUBBLE SORT : stable
//swap amng adjacent elements and keeping largest one at last of unosorted array in every iteration
// 5 1 4 2 8 
void bubbleSort(vector<int>&arr)
{
	int n= arr.size();
	
	bool swapped = false; //to stop swapping if already sorted
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				swapped = true;
			}
		}
		if(swapped == false)
			break;
	}
}
// Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
// Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
// Auxiliary Space: O(1)
// Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
// Sorting In Place: Yes
// Stable: Yes
//--> it is used in a polygon filling algorithm, where bounding lines are sorted by their x coordinate at a specific scan line (a line parallel to x axis) and
// with incrementing y their order changes (two elements are swapped) only at intersections of two lines


//5. SELECTION SORT : (swaps : O(n) at max => useful when memory write operation is costly)

//two subarrays maintained -> 1. sorted & 2. unsorted
//in every iteration minimum element(considering ascend order) from unsorted is picked and placed in sorted sub array
void selectionSort(vector<int> &arr,int n)
{
	
	int minInd;
	for(int i=0;i<n-1;i++)
	{
		minInd = i;
		for(int j =i+1;j<n;j++)
		{
			if(arr[j]<arr[minInd])
				minInd = j;
		}
		swap(arr[minInd],arr[i]);
	}
}
// Time Complexity: (BAW): O(n2) as there are two nested loops.
// Auxiliary Space: O(1)
// The good thing about selection sort is it never makes more than "O(n) swaps" and can be useful when memory write is a costly operation.
// The default implementation is "not stable"
//stable selection sort implementation- https://www.geeksforgeeks.org/stable-selection-sort/



//6. INSERTION SORT : T(B,A,W): (O(n),O(n*2) O(n*2), stable

// 10, 11, 13, 5, 6
void insertionSort(int arr[], int n) 
{ 
	int i, key, j; 
	for (i = 1; i < n; i++) 
	{ 
		key = arr[i]; 
		j = i - 1; 

		while (j >= 0 && arr[j] > key) 
		{ 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
		arr[j + 1] = key; 
	} 
} 

// Time Complexity (B,A,W): (O(n),O(n*2) O(n*2))
// Auxiliary Space: O(1)
// Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted.
// Algorithmic Paradigm: Incremental Approach
// Sorting In Place: Yes (as no aux space reqd)
// Stable: Yes
// Uses: Insertion sort is used when number of elements is small. 
// It can also be useful when input array is "almost sorted", only few elements are misplaced in complete big array.


**********************************************************************

Time Complexities--->

//map
creating a map - O(n)
insertion, deletion - O(1) : unordered map
insertion, deletion - O(logn) : ordered map

**use hash map whenever we want to search element of array in O(1)


Algorithm	Time Complexity
				Best		Average  	Worst	
Selection Sort	Ω(n^2)		θ(n^2)		O(n^2)
Bubble Sort		Ω(n)		θ(n^2)		O(n^2)
Insertion Sort	Ω(n)		θ(n^2)		O(n^2)
Heap Sort		Ω(n log(n))	θ(n log(n))	O(n log(n))
Quick Sort		Ω(n log(n))	θ(n log(n))	O(n^2)
Merge Sort		Ω(n log(n))	θ(n log(n))	O(n log(n))
Bucket Sort		Ω(n+k)		θ(n+k)		O(n^2)
Radix Sort		Ω(nk)		θ(nk)		O(nk)





