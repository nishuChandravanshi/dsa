//todo--> 11,12,14-20
// heap implementation, 
//doc list question ->think soln

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
//1.lcs     // TLE!
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

//coin change II {infinite supply} - No. of ways

https://practice.geeksforgeeks.org/problems/coin-change/0

// LC:
class Solution {   
public:
    
vector<vector<int>> dp;
int makeChange(int i, int nc, vector<int> &v)
{
    // cout<<"i1 "<<i<<"  nc1 "<<nc<<endl;
    
    if(nc == 0)
        return 1;
    if(nc < 0)
        return 0;
    
    if(i >= v.size()) 
        return 0;
    
    if(dp[i][nc] != -1)
        return dp[i][nc];
    
    // cout<<"i "<<i<<"  nc "<<nc<<endl;
    
    int res = 0;
    if(v[i] <= nc)
        res = makeChange(i, nc-v[i],v);
        
    res  += makeChange(i+1, nc,v);
    
    dp[i][nc] = res;
    
    return dp[i][nc];
}

    int change(int amount, vector<int>& coins) {
        
        dp.clear(); 
        for(int i = 0; i < coins.size(); i++)
        {
            vector<int> temp;
            for(int j = 0; j <= amount; j++)
                temp.push_back(-1);
            dp.push_back(temp);
        }
        return makeChange(0,amount, coins);
    }
};


//Coin Change I - Min no. of coins reqd to get the reqd amount

class Solution {
public:
    int minCoins(vector<int>& coins, int amount, vector<int>&res)
    {
        if(amount == 0)
            return 0;
        if(amount < 0)
            return -1;
        
        if(res[amount])
            return res[amount];
        
        int temp = INT_MAX;
        for(int i = 0; i < coins.size(); i++)
        {
            int k = minCoins(coins, amount-coins[i],res);
            if(k == -1)
                continue;
            temp = min(temp, 1+k);
        }
        res[amount] = (temp == INT_MAX) ? -1 : temp;

        return res[amount];        
    }

    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0)
            return 0;
         vector<int> res(amount + 1, 0);
         return minCoins(coins, amount,res);
        
    }
};

//Rod Cutting -max val obtainable by cutting up the rod
//https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

// ip -
//length(8): 1   2   3   4   5   6   7   8  
// price     1   5   8   9  10  17  17  20
// op - 22( length of 2 + length of 6 (5+17))

vector<int>dp(n+1);//init with -1
int cutRod(int price[], int n) 
{ 
	if (n <= 0) 
		return 0; 

	if(dp[n] != -1)
	return dp[n];
	
	int maxVal = INT_MIN; 
	for (int i = 0; i<n; i++) 
		maxVal = max(maxVal, price[i] + cutRod(price, n-i-1)); 

	dp[n] = maxVal;
	
	return dp[n]; 
}

//Rope Cutting - maximize product of lengths of all parts
//https://www.geeksforgeeks.org/maximum-product-cutting-dp-36/

// Input: n = 5
// Output: 6 (2*3)
// Input: n = 10
// Output: 36 (3*3*4)
vector<int>dp; //dp(n+1,-1)
int maxProd(int n) 
{ 
	if (n == 0 || n == 1) return 0; 
 
	if(dp[n] != -1)
		return dp[n];
	
	int maxVal = 0; 
	for (int i = 1; i < n; i++) 
		maxVal = max(maxVal, max(i*(n-i), maxProd(n-i)*i)); 

	dp[n] = maxVal;
	return dp[n]; 
} 
// or--->
//trick:: cut into lengths of 3 as many times as possible before reaching 2 or 3 or 4
int maxProd(int n) 
{ 
   if (n == 2 || n == 3) return (n-1); 
  
   int res = 1; 
   while (n > 4) 
   { 
       n -= 3; 
       res *= 3; 
   } 
   return (n * res);  
} 


//Dice Throw O(m*n*x)- using dp of size n*x

int findWays(int m, int n, int x) 
{ 
	if(x == 0 && n == 0)
	return 1;
	
	if(x <= 0)
		return 0;
	
	
	int sum =0;
	for(int i = 1; i <= m; i++)
	{
		sum += findWays(m, n -1, x - i);
	}
	return sum;
	
} 



// WORD BREAK PROBLEM
// https://practice.geeksforgeeks.org/problems/word-break/0

// dictionary: { i, like, sam, sung, samsung, mobile, ice,
//   cream, icecream, man, go, mango}
// Input:  ilike
// Output: Yes
//s.substr(required_starting_pos, required_length)
//recursion: checking for all possible prefix length
unordered_set<string>dict; //contain dictionary words
bool wordBreak(string str)
{
    int l = str.size();
    if(l==0) return true;
    
    for(int i=1;i<=l;i++)
    {   //substr(i,l)=> substring from i'th index till l length
        if(( dict.find(str.substr(0,i)) != dict.end()) && wordBreak(str.substr(i,l-i)))
            return true;
    }
    return false;
}

//WORD BREAK 2
//https://practice.geeksforgeeks.org/problems/word-break-part-2/0/



//EGG DROPPING PROBLEM
// https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/

//to find "min no of attempts" to get critical floor(ie highest floor from which if egg is dropped it doesnt break) 
//(2 egg, 10 floor) = 4 (attempts to discover critical floor)
//(2,2) = 2
//(3,5) = 3
//(1,k) = k

// (egg,floor)
vector<vector<int>> dp(11,vector<int>(51));
int solve(int n, int k) //return min no of attempts for(n egg , k floors)
{
    if(k==0 || k==1) //0 or 1 floor 
        return k;   //no of attempsts needed
    
    if(n==1)
        return k;   //1 egg, k floor=> k attempts (worst case)
    
    if(dp[n][k]!=0)
        return dp[n][k];
        
    int minAttempts = INT_MAX, res;

    for(int i=1;i<=k;i++) //as we have option to drop egg from 1 to k floors
    {
            res = max(solve(n-1,i-1), solve(n, k-i));    //this will give the maximum possible attempt from ith floor
           
           // ith floor-> 1.if egg breaks=> critical floor is eithr ith or floor below it ie we're left with n-1 egg and i-1 floors(ie solve(n-1,i-1)
           //2.otherwise -> critical floor will be above ith floor and we've same no of eggs as it didnt break from ith floor (ie solve(n, k-i)  
           
            if(minAttempts > res)
                minAttempts = 1+res;//+1 for each attempt
                //this will store the min attempts (resulted from any floor)    
    }
    dp[n][k] = minAttempts;
    return minAttempts;
}
int main() {
    int t; cin>>t;
    while(t--)
    {   
        dp.clear();
        int n,k; cin>>n>>k;

        // (egg,floor)
        cout<<solve(n,k)<<endl;
    }
	return 0;
}



*************************************************


//DBOI Coding round //??discuss
//initially at 0 to reach nth floor
//Find total no. of ways to reach nth floor with following possible moves-
//1. in a single move u can move from i -> i+1th flr : can use this move any no. of time
//2. in a single move u can move from i -> i+2th flr : can use this move any no. of time
//*3. in a single move u can move from i -> i+3rd flr : can use this move atmost k times;
//ip-> t(testcases), n,k
//constrts-> 1<=t<=5*10^5,1<=n<=5*10^5,0<=k<=50
//ip            op
// 5
// 7 3          44
// 4 2          7
// 3 3          4    
// 7 1          41
// 2 3          2

int main() 
{ 
  
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
  int n = 500004;
  int k = 51;
  
  
  long long int dp[500005][52];

  for(int i=0; i<=k; i++)
    dp[0][i] = 1;
    
  long long int mod = 1e9+7;
  for(int i=1; i<=n; i++) {
    for(int j=0; j<=k; j++) {
      dp[i][j] = 0;
      if(i-1>=0)
        dp[i][j] = (dp[i][j]%mod + dp[i-1][j]%mod)%mod;
      if(i-2>=0)
        dp[i][j] = (dp[i][j]%mod + dp[i-2][j]%mod)%mod;
      if(i-3>=0 && j-1>=0)
        dp[i][j] = (dp[i][j]%mod + dp[i-3][j-1]%mod)%mod;
    }
  }

    int t;
    cin>>t;
    while(t--) {
    cin>>n>>k;
    cout<<dp[n][k]<<"\n";
  }
    
  return 0; 
}



*******************************************************************************
// MISC

// CATALAN NUMBER
// https://www.geeksforgeeks.org/program-nth-catalan-number/
//1 1 2 5... (c0,c1,c2,c3....)
vector<int>dp;
int catalan(int n)
{
    if(n<=1)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    
    int res = 0;
    for(int i=0;i<n;i++)
        res += catalan(i)*catalan(n-i-1);
    dp[n] = res;
    return res;
}