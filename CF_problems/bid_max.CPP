#include<bits/stdc++.h>
using namespace std;
main()
{
int n; cin>>n;
int a[n];
for(int i=0 ; i<n ; i++)
cin>>a[i];
sort(a,a+n);
vector<int> v;
v.push_back(a[0]);
for(int i=1 ; i<n ; i++)
if(a[i]!=a[i-1])
v.push_back(a[i]);
long long s[n];
s[0]=v[0];
long long ans=s[0];
n=v.size();
for(int i=1 ; i<n ; i++)
{
if(v[i]==v[i-1]+1)
s[i]=s[i-1]+v[i];
else s[i]=v[i];
ans=max(ans,s[i]);
}
cout<<ans<<endl;
}
