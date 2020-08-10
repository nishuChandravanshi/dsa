#include <bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream/0
int main() {
    int t; cin>>t; 
    while(t--)
    {
        int k, n;
        cin>>k>>n;
        
        int arr[n];
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < k-1; i++)
        {
            pq.push(arr[i]);
            arr[i] = -1;
        }
        pq.push(arr[k-1]);
        arr[k-1] = pq.top();
        
        for(int i = k; i < n; i++)
        {
            if(arr[i] > pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
            arr[i] = pq.top();
            
        }
        
        for(int i = 0; i < n; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    
	return 0;
}
/*
    T: O(nlogk), S:O(k)
ip: k = 4, n = 6
    1 2 3 4 5 6
op: -1 -1 -1 1 2 3
ip: k = 1, n = 2
    3 4
op: 3 4
idea-
-make a min heap of size k. Top element will be the kth largest among k
-compare top of heap, one by one with array elements
if array element is greater than top-> pop top ie smaller element and push array element(ie larger)

*/

