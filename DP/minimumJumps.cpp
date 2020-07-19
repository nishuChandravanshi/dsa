
#include<bits/stdc++.h>

using namespace std;

int minimumJumps(int[], int);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minimumJumps(arr, n)<<endl;    // Function to calculate minimum number of jumps
    }
    return 0;
}
int minimumJumps(int arr[], int n){
    
    if(arr[0] == 0) return -1;
    int jumps[n];       //will contain min no of steps to reach ith index from 0, in arr
    jumps[0] = 0;
     
    for(int i = 1; i < n; i++){
        jumps[i] = INT_MAX;
        for(int j = 0; j < i; j++){
            if(i <= (j + arr[j]) and arr[j] != 0) //checking if i is reachable from j
                jumps[i] = min(jumps[i], jumps[j] + 1);
    
        }
    }
    if(jumps[n-1] == INT_MAX) return -1;
    return jumps[n-1];
}
