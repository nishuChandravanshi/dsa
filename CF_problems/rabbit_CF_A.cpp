#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		long long x,y,a,b;
		cin>>x>>y>>a>>b;
		
		if((y-x)%(a+b)==0)
		cout<<(y-x)/(a+b)<<endl;
		else
		cout<<"-1"<<endl;
		
	}
	return 0;
}
