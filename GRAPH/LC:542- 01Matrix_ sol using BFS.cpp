class Solution {
public:             //BFS:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return matrix;
        
        int m= matrix.size();
        int n= matrix[0].size();
        
        queue<vector<int>>q;
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                    q.push({i,j});  //keeping track of 0s as these indices are already smallest distance indices
                else 
                    matrix[i][j]=INT_MAX;
            }
        
        int i,j;
        while(!q.empty()){
            
            vector<int>curr= q.front();
            q.pop();
            
            
            //i,j
            i= curr[0]; 
            j=curr[1];
            
            
            //visitng neighbours ie (+1,0),(-1,0),(0,+1),(0,-1)
            // if out of bound or already smaller distance dont do anything, go for next neighbour
            
            if( i+1<m and matrix[i+1][j] > matrix[i][j]+1)               
            {
                q.push({i+1,j}); //updating new smaller distance value
                matrix[i+1][j]= matrix[i][j]+1;
            }
            
  
            if(  i-1>=0 and matrix[i-1][j] > matrix[i][j]+1)
            {
                q.push({i-1,j});
                matrix[i-1][j]= matrix[i][j]+1;
            }
            
            
            if( j+1<n and matrix[i][j+1] > matrix[i][j]+1)
            {
                q.push({i,j+1});
                matrix[i][j+1]= matrix[i][j]+1;
            }
            
            
            if( j-1>=0 and matrix[i][j-1] > matrix[i][j]+1)
            {
                q.push({i,j-1});
                matrix[i][j-1]= matrix[i][j]+1;
            }
            
        }
        
        return matrix;
    }
};

