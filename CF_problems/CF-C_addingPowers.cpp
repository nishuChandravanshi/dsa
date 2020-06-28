#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
		int n,k;cin>>n>>k;
		bool v[n]={0};
		long long a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		for(int i=0;i<n;i++)
		{
			long long r=pow(k,i);
			if(a[i]%r==0)
				v[i]=true;
			else break;
		}
		if(v[n-1]==true)
		cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	
	return 0;
}
