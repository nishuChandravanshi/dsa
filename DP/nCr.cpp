#include<bits/stdc++.h> 
using namespace std; 

const int p = 1e9+7;

int nCrModp(int, int);

int main() 
{ 
  int t, n, r;
  cin >> t;
  
  while(t--){
      cin >> n >> r;
      cout << nCrModp(n, r) << endl;
  }
  
  return 0; 
}

// Returns nCr % p 
int nCrModp(int n, int r) 
{ 
  if(r>n) return 0;

  int res[n+1][r+1];
  
  for(int i = 0; i <= n; i++){
      for(int j = 0; j <= min(n,r); j++){
          if(j == 0 or j == i)
                res[i][j] = 1;
            else 
                res[i][j] = res[i-1][j-1]%p + res[i-1][j]%p;
      }
  }
  return res[n][r]%p;
  
} 

