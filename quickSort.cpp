#include <bits/stdc++.h>
using namespace std;

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
	//ind+1 gives the right position of the pivot, after sorting the smaller elements to left and larger to right
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
