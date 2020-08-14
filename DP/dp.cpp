//todo--> 11,12,14-20
//sort(quick, merge), heap implementation, 
//doc list question ->think soln-> note those with not confidence

//LCS
// S : ahirsjbj
// P : abcdbbeu

int lcs(int i, int j) {
    if(i==m || j==n) {
        return 0;
    }

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(s[i]==p[j]) {
        dp[i][j] = 1+lcs(i+1, j+1);
    }
    else {
        dp[i][j] = max(lcs(i+1, j), lcs(i, j+1));
    }
    return dp[i][j];
}
//shortest common supersequence-> length of string which has both a,b as its sub-sequence
//=> (a.length() + b.length() - LCS)


//LIS
//A: [1,2,3,1,5,4, 7, 8 ,9]
int lis(int i) {  //O(n^2)
    if(i==n)
        return 0;

    if(dp[i]!=-1)
        return dp[i];

    for(int j=i+1; j<n; j++) {
        if(a[j]>a[i]) {
            dp[i] = max(dp[i], 1+lis(j));
        }
    }

    return dp[i];
}

for(int i=0; i<n; i++)
    res = max(res, lis(i));

return res;




//EDIT Distance
// S: abcdefgh
// P: abdsfrg  

//1-> Insert, 2->Replace, 3->Delete  1unit

int solve(int i, int j) {

    if(i==m && j!=n) {
        return n-j;
    }
    else if(j==n && i!=m) {
        return m-i;
    }
    else if(i==m && j==n)
        return 0;

    if(s[i]==p[j]) {
        return solve(i+1, j+1);
    }
    else {           //insert          replace          delete
        return 1+min(solve(i+1, j), solve(i+1, j+1), solve(i, j+1)); 
    }
}

//find if there's a subset with sum equal to given target
//A: [1, 2, 4 ,5 , 5]  target = 8
//dp[n][sum(a)]
bool solve(int i, int sum) {
    if(i==n)
        return false;

    if(dp[i][sum]!=-1)
        return dp[i][sum];

    if(sum==target)
        dp[i][sum] = true;

    dp[i][sum] = solve(i+1, sum+a[i]) || solve(i+1, sum)
    return dp[i][sum];
}

//minimum partition
//A: [1, 2, 4, 5, 2, 5]
//S-> S/2 S/2-1 S/2-2----->0 diff 0

//Count number of ways to reach the top
//0 1 2 3 .....n [steps->1,2,3]

int solve(int i) {
    if(i==n)
        return 1;

    if(dp[i]!=-1)
        return dp[i];

    dp[i] = solve(i+1)+solve(i+2)+solve(i+3);
    return dp[i];
}   


//longest path in matrix
// Input:  mat[][] = {{0, 2, 3}  
//                    {5, 3, 4}
//                    {4, 6, 5}}

//    {{1, 2, 9}
//    {5, 3, 8}
//    {4, 6, 7}}
// Output: 4
// The longest path is 6-7-8-9. 

int solve(int i, int j) {

    if(dp[i][j]!=-1)
        return dp[i][j];

    vis[i][j] = 1;
    vector<pair<int, int >>neigh;
    if(i-1 >=0)
        neigh.push_back(make_pair(i-1, j));
    if(i=1<n)
        neigh.push_back(make_pair(i+1, j));
    if(j-1>=0)
        neigh.push_back(make_pair(i, j-1));
    if(j+1<m)
        neigh.push_back(make_pair(i, j+1));
    
    int res = 0;
    for(auto child: neigh) {
        if(!vis[child.first][child.second] && (mat[child.first][child.second]-mat[i][j])==1) {
            res = max(res, 1+solve(child.first, child.second));
        }
    }
    dp[i][j] = res;
    return res;
}

int ans = 0;
for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
        ans= max(ans, solve(i, j), make_pair(-1, -1));

return ans;


//Optimal Strategy for game
//A: [2, 1, 3, 4, 5]
//A, B: diff(A-B)

//diff of a and b
int solve(int l, int h, int d, int t) {

    if(l>h) {
        return d;
    }

    if(t==0) {
        return max(solve(l+1, h, d+a[l], 1), solve(l,h-1, d+a[h], 1));
    }
    else {
        return min(solve(l+1, h, d-a[l], 0), solve(l, h-1, d-a[h],0));
    }
}

//sum of array ->s
// s = x+y 
// d = x-y

//0-1 Knapsack
weight = {2,1,3,}
cost = {211,31,3}
W :max wt

int solve(int i, int w) {

    if(w==0) {
        return 0;
    }

    if(i==n)
        return 0;

    if(w>weight[i])
        res = max(res, cost[i]+solve(i, w-weight[i]))
    res = max(res, solve(i+1, w));
    return res;
}

//minimum health reduction, can skip atmost one step
int solve(int i)
{
    if(i >= n)
        return 0;

    return a[i] + min(solve(i+1), solve(i+2));
}

//*****************************************************************************
//1.lcs     //?? TLE!
//https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
/*
ABCDGH
AEDFHR
*/
int lcs(int i, int j, string a, string b, vector<vector<int>> &dp)
{
    if((i >= a.length()) or (j >= b.length()))
        return 0;
    
    if(dp[i][j] != 0)
        return dp[i][j];
    
    if(a[i] == b[j])
        dp[i][j] = 1 + lcs(i+1, j+1, a, b, dp);
    else
        dp[i][j] = max(lcs(i+1, j, a, b, dp), lcs(i, j+1, a, b, dp));

    return dp[i][j];
}
int main() {
    int t; cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        
        string a, b;
        cin>>a>>b;
        
        vector<vector<int>> dp(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                dp[i].push_back(0);
        
        int lseq = lcs(0,0,a,b,dp);
        
        cout<<lseq<<endl;
    }
    
	return 0;
}

//2. LIS
// 16
// 0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15 ->ans 6
//6
//5 8 3 7 9 1 -> ans 3

int solve(int i, vector<int> &v, vector<int> &dp)
{
    if(i == v.size() - 1)
        return 1;
    if(dp[i] != -1) 
        return dp[i];
    
    for(int j = i+1; j < v.size(); j++)
        if(v[j] > v[i])
            dp[i] = max(dp[i],1+solve(j, v, dp));
    
    return dp[i];
}

int main() {
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            int a; 
            cin>>a;
            v.push_back(a);
        }
        vector<int> dp(n,-1);
        int ans = INT_MIN;
        for(int i = 0; i < n; i++)
             ans = max(ans,solve(i,v,dp));
        
        cout<<ans+2<<endl;
    }
	return 0;
}


//3. Edit Distance //?? wrong ans

int minEdits(int i, int j, string a, string b,vector<vector<int>> &dp)
{
    if(i == a.length() && j == b.length())
    {
        return 0;
    }
    else if(i == a.length() && j != b.length())
    {
        return b.length() - j;
    }
    else if(j == b.length())
    {
        return a.length() - i;
    }
    if(dp[i][j] != -1)
        return dp[i][j];

    int res;
    if(a[i] == b[i])
        res = minEdits(i+1, j+1, a, b,dp);
    else        
        res = 1+ min({minEdits(i+1, j, a ,b,dp),
                    minEdits(i, j+1, a, b,dp),
                    minEdits(i+1, j+1, a, b,dp)});
    dp[i][j] = res;
    
    return res;
}

int main() {
    int t; cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        
        string a, b;
        cin>>a>>b;
        
        vector<vector<int>> dp(n);
        for(int i = 0; i < n; i++)
            for(int j =0; j < m; j++)
                dp[i].push_back(-1);
            
        cout<<minEdits(0,0,a,b, dp)<<endl;
        // minEdits(0,0,a,b, dp);
        // cout<<dp[n-1][m-1]<<endl;
        for(int i = 0; i < n; i++){
            for(int j =0; j < m; j++)
                {
                    cout<<dp[i][j]<<" ";
                }
            cout<<endl;
        }
            
        
    }
	return 0;
}
//5. no of ways to reach top
int noOfWays(int i, int n, vector<int>&dp)
{
    if(i > n)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    if(i == n)
        return 1;
    int ans = noOfWays(i+1,n,dp)+noOfWays(i+2,n,dp)+noOfWays(i+3,n,dp);
    dp[i] = ans;
    return ans;
}

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    vector<int> dp(n+1,-1);
	    cout<<noOfWays(0, n,dp)<<endl;
	}
	return 0;
}

//7.subset sum problem- list can be partitioned into two equal sum subset or not
bool findSum(int i,vector<int>&v, int sum,vector<vector<int>>&dp)
{
    if(i >= v.size() or sum < 0)
        return 0;
    if(dp[i][sum] != -1)
        return dp[i][sum];
    if(sum == 0)
        return 1;
    
    dp[i][sum] = findSum(i+1, v, sum - v[i],dp) || findSum(i+1, v, sum,dp);

    return dp[i][sum];    
}
int main() {
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<int> v;
        
        int sum = 0;
        for(int i =0; i < n; i++)
        {
            int a; cin>>a;
            v.push_back(a);
            sum += a;
        }
        if(sum%2 == 1){
            cout<<"NO\n";
        }
        else{
            sum /= 2;
            vector<vector<int>> dp(n);
            for(int i =0; i<n; i++)
            {
                for(int j =0; j <= sum; j++)
                    dp[i].push_back(-1);
            }
            
            bool flag = findSum(0,v,sum,dp);
            if(flag)
                cout<<"YES\n";
            else cout<<"NO\n";
            
        }
    }
	return 0;
}

//Path in matrix -diff from longest path problem
//https://practice.geeksforgeeks.org/problems/path-in-matrix/0
long long maxSum(int i, int j, vector<vector<long long>> &v, vector<vector<long long>> &dp)
{
    if(i < 0 or i >= v.size())
        return 0;
    if(j < 0 or j >= v.size())
        return 0;
    if(dp[i][j] != 0)
        return dp[i][j];
    
    dp[i][j] = v[i][j] + max({maxSum(i+1,j,v,dp),
                            maxSum(i+1,j-1,v,dp),
                            maxSum(i+1,j+1,v,dp)});
    
    return dp[i][j];
}


int main() {
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<vector<long long>> v(n);
        vector<vector<long long>>dp(n);
        for(int i=0; i<n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                long long a; cin>>a;
                v[i].push_back(a);
                dp[i].push_back(0);
            }
        }
        long long sum =0;
        for(int i = 0; i<n; i++)
            sum = max(sum, maxSum(0,i, v, dp));
        
        cout<<sum<<endl;
    }
	return 0;
}

//knapsack
int maxValue(int i, vector<int> &cost, vector<int> &weight, int mw,vector<vector<int>> &dp)
{
    if(i >= weight.size())
        return 0;
        
    if(mw == 0)
        return 0;
        
    if(dp[i][mw] != -1)
        return dp[i][mw];
    
    int res =0;
    if(weight[i] <= mw)
        res = max(cost[i]+maxValue(i+1,cost,weight, mw-weight[i],dp),
                maxValue(i+1,cost,weight,mw,dp));
    else
        res = max(res, maxValue(i+1,cost,weight,mw,dp));
    
    dp[i][mw] = res;
    return res;
}

int main() {
    int t; cin>>t;
    while(t--)
    {
        int n, mw;
        cin>>n>>mw;
        
        vector<int> cost(n), weight(n);
        
        for(int i =0; i < n; i++)
            cin>>cost[i];
        for(int i =0; i < n; i++)
            cin>>weight[i];
        
        vector<vector<int>> dp(n+1);
        for(int i =0; i<n; i++)
            for(int j = 0; j<=mw; j++)
                dp[i].push_back(-1);
        
        cout<<maxValue(0,cost,weight,mw,dp)<<endl;
    }
	return 0;
}

//coin change -->>?? wrong ans
#include <bits/stdc++.h>
https://practice.geeksforgeeks.org/problems/coin-change/0
using namespace std;
vector<vector<int>> dp(302);
int makeChange(int i, int nc, vector<int> &v)
{
    if(nc == 0)
        return 1;
    if(nc < 0)
        return 0;
    
    if(i >= v.size() or v[i] > nc) 
        return 0;
    
    if(dp[i][nc] != -1)
        return dp[i][nc];
    
    int res;
    res  = makeChange(i, nc-v[i],v)+
          makeChange(i+1, nc,v);
    
    dp[i][nc] = res;
    
    return dp[i][nc];
}

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    
	    vector<int> v(n);
	    for(int i = 0; i < n; i++ )
	        cin>>v[i];
	    
	    int nCents; cin>>nCents;
	    
	    for(int i = 0; i < n; i++)
	        for(int j =0; j <= nCents; j++)
	            dp[i].push_back(-1);
	    
	    cout<<makeChange(0,nCents, v)<<endl;
	    
	}
	return 0;
}

// Word Break problem
//s.substr(required_starting_pos, required_length)
