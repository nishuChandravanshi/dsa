#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int coinChange(int n,vector<int>&dp)
{
	
	if(n<0)
		return 0;
	if(n==0)
		return 1;
	
	if(dp[n])
		return dp[n];
	
	int ans = 0;
	for(int k=1;k<=6;k++)
		ans = (ans%mod+ coinChange(n-k,dp)%mod)%mod;
	
	dp[n] = ans;
	return dp[n];
}

int main() {
	int n; cin>>n;
	vector<int>dp(n+1,0);
	cout<<coinChange(n,dp)<<endl;
	
	return 0;
}

