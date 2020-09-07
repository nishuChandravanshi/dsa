//COUNT OF SUBARRAYS WITH GIVEN SUM (k) --(subarray ie contiguous)

//T: O(n^2), S:O(n): prefix Sum
// https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum/0#:~:text=Given%20an%20unsorted%20array%20arr,the%20number%20of%20test%20cases./

//sumOfSubset from l to r(lets say :val) == preSum[r]-preSum[l-1]
//if(val == k) count++; where k is the given sum;
//10 2 -2 -20 10, k=-10 -> op: 3
// 1 4 20 3 10 5, k = 33 -> op: 1

vector<int> preSum(n);
preSum[0]=a[0];
for(int i=1;i<n;i++)
    preSum[i] = preSum[i-1]+a[i];
        
// 10 2 -2 -20 10
int count =0;
for(int r=0;r<n;r++)
{
    for(int l = 0; l<=r;l++)
    {
        //sum of subset from l to r
        if(l && (preSum[r]-preSum[l-1] == k))
            count++;
        else if(l==0 && (preSum[r] == k))
            count++;
    }
}
cout<<count<<endl;



//EFFICIENT : T: O(n) S: O(n) 

//let val = preSum[r] - preSum[l-1] (if val == k it means subarray(l to r) with sum k is present)
//now if val is present => val = k => k = preSum[r]-preSum[l-1] 
//now preSum[r] - k = preSum[l-1] => if(preSum[r]-k) is present in any preSum previously calc then it must be preSum[l-1]-->
// ie a valid subarray is present with sum k is present if we find preSum[r]-k as prefix sum found till now(ie till r)



#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--)
    {
        int n; cin>>n; 
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        int k; cin>>k;
        
        unordered_map<int,int> mp;
        int preSum =0;
        // 10 2 -2 -20 10
        int count =0;
        for(int r=0;r<n;r++)
        {
            preSum += a[r];
            if(preSum == k)
            {
               count += 1;
            }    
            if(mp.find(preSum-k) != mp.end())
            {
                count += mp[preSum -k];
            } 
            mp[preSum]++;
        
        }
        cout<<count<<endl;
    }
	return 0;
}




