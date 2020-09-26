
// M[][]: input matrix
// n: size of matrix (n*n)

int findCeleb(int n)
{
    if(n == 1)
        return n-1;
    
    int id = findCeleb(n-1);
    
    if(id == -1)    //if there aint any celeb among n-1 ppls then nth one(ie n-1 th) can be celeb
        return n-1;
    
    else if( M[n-1][id] and !M[id][n-1])// if nth person knows id and id doesnt knows nth(n-1) person=> id is celeb
        return id;
    else if( M[id][n-1] and !M[n-1][id])// if nth !knows id and id knows nth = nth is celeb
        return n-1;
        
    return -1;
}


int getId(int M[MAX][MAX], int n)
{
    
    int id = findCeleb(n);
    
    //to check if the obtained id is really  a celeb 
    if(id == -1)
        return id;
    else{
        int c1 = 0, c2 = 0;
        
        for(int i = 0; i < n; i++)
        {
            c1 += M[id][i]; //=> id knows i : eqv to knows(id, i)
            c2 += M[i][id];
        }
    if(c1 == 0 and c2 == n-1)
        return id;
    }
    
    return -1;
}




// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

// } Driver Code Ends


/*
    T: O(n), S: O(1)
-here n-1 => nth person(since 0 indexing)
*/
