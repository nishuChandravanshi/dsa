#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		double x,y,a,b;
		cin>>x>>y>>a>>b;
		double t1;
		t1=(y-x)/(a+b);
		// cout<<t1<<endl;
		long long k= (long long)t1;
		if(t1<1 or t1!=k)
		cout<<"-1"<<endl;
		else
		cout<<t1<<endl;
	}
	return 0;
}
