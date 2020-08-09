#include <bits/stdc++.h>
using namespace std;
const int r = 100, c = 100;

//efficient T:O(R*C), S:O(R*C)
int getTimeToRot(int arr[r][c], int n, int m)
{
    
    int ans = 0;
    queue< pair<int, int>> q;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 2)
                q.push({i,j});
        }
    }
    
    while(!q.empty())
    {
        int frame = q.size();
        bool changed = false;

        while(frame--)
        {
            pair<int, int> p = q.front();
            int i = p.first;
            int j = p.second;

            q.pop();

            if(i - 1 >= 0 and arr[i-1][j] == 1)
            {
                q.push({i-1,j});
                arr[i-1][j] = 2;
                changed = true;
            }
                
            if(i + 1 < n and arr[i+1][j] == 1)
             {
                q.push({i+1,j});
                arr[i+1][j] = 2;
                changed = true;
             }
            if(j - 1 >= 0 and arr[i][j-1] == 1)
            {
                q.push({i,j-1});
                arr[i][j-1] = 2;
                changed = true;
            }
            if(j + 1 >= 0 and arr[i][j+1] == 1)
            {
                q.push({i,j+1});
                arr[i][j+1] = 2;
                changed = true;
            }

        }
        if(changed)
            ans++;
    }
    
    //checking if theres any fresh orange left => it wont be affected by rotten oranges 
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr[i][j] == 1)
                return -1;
    
    return ans; 
}

/*      T:O(R*C)  
ip -  { { 2, 1, 0, 2, 1 }, 
        { 1, 0, 1, 2, 1 }, 
        { 1, 0, 0, 2, 1 }};
op- 2
Ipt:  { {2, 1, 0, 2, 1},
        {0, 0, 1, 2, 1},
        {1, 0, 0, 2, 1}};
Op: -1

idea- BFS: queue used to store rotten oranges in each time frame
-intialize timeRequire(ans) = 0
-insert all rotten oranges in queue
    -pop one by one and insert their adjacent fresh oranges in queue,
    making them rotten in original array
- if any fresh oranges were turned into rotten from prev rotten oranges
    then change is marked true and time frame increases by 1(ans++)
    in each iteration
*/


// Naive apprch T: O(max(R,C)*R*C) S:O(1)
int getTimeToRot(int arr[r][c], int n, int m)
{
    
    int rotten = 2;
    bool changed = false;
    
    int totalTime = 0;
    while(true)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                
                if(arr[i][j] == rotten)
                {
                    if(i - 1 >= 0 and arr[i-1][j] == 1)
                    {
                        arr[i-1][j] = arr[i][j]+1;
                        changed = true;
                    }
                    if(i + 1 < n and arr[i+1][j] == 1)
                    {
                        arr[i+1][j] = arr[i][j]+1;
                        changed = true;
                    }
                    if(j - 1 >= 0 and arr[i][j-1] == 1)
                    {
                        arr[i][j-1] = arr[i][j]+1;
                        changed = true;
                    }
                    if(j + 1 < m and arr[i][j+1] == 1)
                    {
                        arr[i][j+1] = arr[i][j]+1;
                        changed = true;
                    }
                            
                }
                    
            }
        }
        if(!changed)
            break;
        changed = false;
        
        rotten++;
        
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr[i][j] == 1)
                return -1;
    
    return rotten - 2; //as initially rotten was already 2 then it got increamented by 1 after every iteration
}



int main() {
	int t; cin>>t; 
	while(t--)
	{
	    int n, m;
	    cin>>n>>m;
	    int arr[r][c];
	    
	    if(n == 1 and m == 1)
	    {
	        if(arr[0][0] != 2)
	        cout<<"-1\n";
	        else cout<<"0\n";
	        break;
	    }
	        
	    int count1 = 0, count2 = 0;
	    
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < m; j++)
	        {
	            cin>>arr[i][j];
	            if(arr[i][j] == 1)
	                count1++;
	            else if(arr[i][j] == 2)
	                count2++;
	        }
	    }
	    
	    if(count2 == 0)
	        cout<<"-1\n";
	   else
	    cout<<getTimeToRot(arr, n, m)<<endl;
	}
	
	return 0;
}

/*
		naive- T: O(max(R,C)*R*C) S:O(1) 
idea-
-convert all possible fresh oranges to rotten, updating new converted rotten as 3 so as next time 
fresh oranges adjacent to these newly rotten(3) wil be rotten and so..
-similary in every iteration newly rotten will be assigned (+1 old rotten)
value so as to ditinguish the different no of iteration(inorder to calculate 
no of passes required to convert all of'em into rotten)
*/

