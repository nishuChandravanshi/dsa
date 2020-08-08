#include <bits/stdc++.h>
using namespace std;

long long int merge(vector<int> &v, vector<int> &temp, int l, int mid, int r)
{
    int i = l;
    int j = mid;
    long long int invCount = 0;
    
    int t = i;  //temp will be updated from i
    while((i <= mid-1) and j <= r)
    {   
        if(v[i] <= v[j]) //remeber even in case of == push v[i] first to count inversions properly, else itll be distorted
            temp[t++] = v[i++];
        else
        {
            temp[t++] = v[j++];
            invCount += mid - i;
        }
    }
    
    while( i <= mid -1 )
        temp[t++] = v[i++];
    
    while(j <= r)
        temp[t++] = v[j++];
        
    for(int i = l; i <=r; i++)
        v[i] = temp[i];
    
    return invCount;
}

long long int mergeSort(vector<int>&v, vector<int> &temp, int l, int r)
{
    long long int invCount = 0;
    if(l < r)
    {
        int mid = l + (r-l)/2;
        
        invCount += mergeSort(v, temp, l, mid);
        invCount += mergeSort(v, temp, mid+1, r);
        
        invCount += merge(v, temp, l, mid+1, r);
    }
    
    return invCount;
}

long long int mergeSort(vector<int> &v, int n)
{
    vector<int> temp(n);
    
    return mergeSort(v, temp, 0, n-1);
}

int main() {
    int t; cin>>t; 
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            int a; cin>>a;
            v.push_back(a);
        }
        
        cout<<mergeSort(v, n);
    }
    
	return 0;
}

/*
    T: O(nlogn), S:O(n)
ip: 8 4 3 2 
op: 6

op<->inversion count and sorted array(if dont want to modify original
array -> make a copy of original and proceed)
idea- 
-use merge sort to count inversions
-for a[i] > a[j] => (mid-i) inversion : cuz
left and right subarrays are sorted,
so all the remaining elements in left-subarray
(a[i+1], a[i+2] … a[mid]) will be greater than a[j]

*/
