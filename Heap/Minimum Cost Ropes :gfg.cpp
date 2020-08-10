#include <bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/connect-n-ropes-minimum-cost/
int main() {
    int t; 
    cin>>t;
    while(t--)
    {
        int n; cin>>n;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < n; i++)
        {
            int v; cin>>v;
            pq.push(v);
        }
        if(n == 1)
        {
            cout<<pq.top()<<endl;
            break;
        }
        
        long long int minCost = 0;
        long long int a = 0;
        while(!pq.empty())
        {
            a = pq.top();
            pq.pop();
            if(!pq.empty())
            {
                a += pq.top();
                pq.pop();
            }
            
            minCost += a;
            
            if(!pq.empty())
                pq.push(a);
        }
        
        cout<<minCost<<endl;
    }
    
	return 0;
}
/*
        T: O(nLogn), S: O(n)
{T->assuming that we use a O(nLogn) sorting algorithm}.
Note that heap operations like insert and extract take O(Logn) time.

ip- 4 3 2 6
op- 29 {(2+3) + (5+4) + (9+6)}

idea-
-greedy approach-> take 2 minimum length roaps first using pq - sum it- push it back into the pq
-meanwhile keep updating the cost
*/

