
int tour(petrolPump p[],int n)
{
    int capacity = 0, deficit = 0;
    int start = 0;
    
    for(int i = 0; i < n; i++)
    {
        capacity += p[i].petrol - p[i].distance;
        
        if(capacity < 0)    //if -ve => till i there cant be circular tour so updating start = i+1
        {
            start = i + 1;
            deficit += capacity; //as for end to come back to start it should have cap >= abs(deficit) so as to make the circular tour possible 
            capacity = 0;
        }
    }
    
    return (capacity + deficit) > 0 ? start%n : -1;
    
}


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [],int );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}
// } Driver Code Ends





/*
	T: O(n), S: O(1)	
Input:
1
4
4 6 6 5 7 3 4 5
Output:
1
*/
