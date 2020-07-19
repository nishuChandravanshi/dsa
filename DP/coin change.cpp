#include <bits/stdc++.h>
using namespace std;

long long minimumNoOfCoins(int coins[], int n, int value, long long cache[]){
    if(value == 0) return 0;
    
    long long mn = INT_MAX;

    for(int i = 0; i < n; i++){
        
        if(value - coins[i] >= 0)
        {
            long long c;
            
            if(cache[value - coins[i]] > 0)
                c = cache[value - coins[i]];
            else{
                
                c = minimumNoOfCoins(coins, n, value - coins[i], cache);
                cache[value - coins[i]] = c;
            }
            mn = min(mn, c+1);
            
        }
            
    }
    return mn;
}

long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
{
    int n = numberOfCoins;
    long long cache[value + 1] = {-1};
    
    
    long long ans = minimumNoOfCoins(coins,n,value, cache);
    
    if(ans != INT_MAX) return ans;
    else return -1;
}

int main() {
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    int value;
	    cin>>value;
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    
	    int answer=minimumNumberOfCoins(coins,numberOfCoins,value);
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}
