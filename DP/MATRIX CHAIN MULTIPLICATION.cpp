
//MIN COST OF MULTPLICATION
// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
// In a chain of matrices of size n, we can place the first set of parenthesis in n-1 ways. For example, if the given chain is of 4 matrices. let the chain be ABCD, 
// then there are 3 ways to place first set of parenthesis outer side: (A)(BCD), (AB)(CD) and (ABC)(D).

//idea-> placing parenthesis in every pos pos and getting the min cost
// Input: p[] = {10, 20, 30, 40, 30} 
// Output: 30000 
// Input: p[] = {10, 20, 30}  
//Output: 6000  (only 1 way)

#define ll long long
int dp[105][105];
int multi(vector<int> &a, int i, int j) 
{ 
    if(i >= j)
        return 0;
	
	if(dp[i][j]!=0)
	    return dp[i][j];
	int count =0;
	int mn =INT_MAX;
	//placing parenthesis(ie k) b/w i-1 to j (diff pos)
	for(int k=i;k<j;k++)
	{
	    count = multi(a,i,k) + multi(a, k+1,j) + a[i-1]*a[k]*a[j];
	    mn = min(count,mn);
	}
	dp[i][j] = mn;
	return dp[i][j];
} 

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
    
        //dp initializing
        for(int i=0;i<105;i++)
            for(int j=0;j<105;j++)
                dp[i][j] = 0;
    
        //notice: (1,n-1) --> 1 indicating pos of parenthesis  
        cout<<multi(a,1,n-1)<<endl;
    }
	return 0;
}

