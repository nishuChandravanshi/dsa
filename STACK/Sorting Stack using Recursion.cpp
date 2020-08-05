	//sorting stack using Recursion

void sortedInsert(stack<int> &s, int val)
{
    if(s.empty()){
        s.push(val);
        return;
    }
    int t = s.top();
    if(val >= t){
        s.push(val);
        return;
    }
   else{ 
    
    s.pop();
    sortedInsert(s, val);
    s.push(t);
       
   }
}

void SortedStack :: sort()
{
    if(s.empty())
        return;
    
    int t = s.top();
    s.pop();
    sort(); 
    sortedInsert(s, t);
}



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*
	T:O(n^2), S: recursive stack-O(n)
*/
