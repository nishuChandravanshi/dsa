
//NQueen -ALL SOLUTIONS 

// https://www.geeksforgeeks.org/printing-solutions-n-queen-problem/
//https://practice.geeksforgeeks.org/problems/n-queen-problem/0
// Input
// 2
// 1
// 4
// Output:
// [1 ]
// [2 4 1 3 ] [3 1 4 2 ]


bool isSafe(int r, int c, vector<vector<int>> &mat)
{
    for(int i=0;i<=c;i++)
    {
        if(mat[r][i] ==1)
            return false;
    }
    //upper diagonal
    for(int i=r,j=c; i>=0 && j>=0; i--,j--)
        if(mat[i][j] == 1)
            return false;
    //lower diag
    for(int i=r,j=c; i<mat.size() && j >=0; i++,j--)
        if(mat[i][j] == 1)
            return false;
    
    return true;
}

void printSol(vector<vector<int>>&mat)
{
    cout<<"[";
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat.size();j++)
            if(mat[j][i] == 1)
                if(i<mat.size()-1)
                    cout<<j+1<<" ";
                else cout<<j+1;
    }
    cout<<" ] ";
    
}
bool solve(int col, vector<vector<int>>& mat)
{
    if(col>=mat.size())
    {
        printSol(mat);
        return true;
    }
        
    bool res = false;
    //to find safe row for col 
    for(int i=0;i<mat.size();i++)
    {
        if(isSafe(i,col,mat))
        {
            mat[i][col] = 1;
            
            res |= solve(col+1,mat);    //if to find only one sol then return here ie-> if(solve(col+1,mat)) return true;
            
            mat[i][col] = 0;
        }
    }
    return res;
}

int main() {
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<vector<int>> mat(n,vector<int>(n,0));
        
        bool ans =solve(0,mat);
        if(!ans)
            cout<<"-1";
        cout<<endl;
    }
    
	return 0;
}