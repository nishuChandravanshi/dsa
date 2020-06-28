#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,m;
	string s,sr,md,t,y;
	cin>>n>>m;
	map<string, int>mp;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		sr=s;
		reverse(sr.begin(),sr.end());
		if(sr==s)
		md=sr;
		if(mp.find(sr)!=mp.end())
		{
			t+=s;
			y=sr+y;
			mp.erase(s);
		}
		else mp[s]++;
		
	}
	cout<<t.size()+md.size()+y.size()<<endl<<t+md+y<<endl;
	return 0;
}
