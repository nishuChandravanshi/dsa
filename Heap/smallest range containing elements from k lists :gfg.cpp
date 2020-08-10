
//https://www.geeksforgeeks.org/find-smallest-range-containing-elements-from-k-lists/
#include<queue>
void findSmallestRange(int arr[][N], int n, int k)
{
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    
    int maxim = INT_MIN;
    int minRange = INT_MAX;
    pair<int, int> range;
    
    for(int i = 0; i < k; i++)
    {
        pq.push({arr[i][0], i});
        maxim = max(arr[i][0], maxim); 
    }
    // cout<<maxim<<endl;
    range = {pq.top().first, maxim};
    // cout<<range.first<<endl;
    minRange = maxim - range.first;
    int i;
    
    vector<int> v(k,0);
    
    while(true)
    {
        i = pq.top().second;
        pq.pop();
        v[i]++;
        
        if(v[i] >= n)	//if any list exhaust then return the min range found till now
            break;
        
        pq.push({arr[i][v[i]], i});
        if(arr[i][v[i]] > maxim)
            maxim = arr[i][v[i]];
        
        std::pair<int, int> smallest = pq.top();
        
        if(minRange > maxim - smallest.first)
        {
            minRange = maxim - smallest.first;
            range = {smallest.first, maxim};
        }
        
    }
    cout<<range.first<<" "<<range.second<<endl;
    
}


/*
			T: O(nklogk), S:O(k) 

T: O(nklogk)
To find the maximum and minimum in an Min Heap of length k the time required is O(log k), and to traverse all the k arrays of length n (in worst case), the time complexity is O(n*k), then the total time complexity is O(n * k *log k).
S: O(k).
The priority queue will store k elements so the space complexity os O(k)

ip-
n = 5, k = 3 
1 3 5 7 9
0 2 4 6 8
2 3 5 7 11
op - (1,2)

ip-
1 2 3 4
5 6 7 8
9 10 11 12
op - (4,9)

*/


// { Driver Code Starts
#include<iostream>
#include<limits.h>
using namespace std;
#define N 1000

void findSmallestRange(int arr[][N], int n, int k);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
	    findSmallestRange(arr, n, k);
    }   
	return 0;
}

// } Driver Code Ends

