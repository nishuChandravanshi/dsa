// Largest square formed in a matrix 
// https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
// https://leetcode.com/problems/maximal-square/submissions/
// 0 1 0 1 0 1
// 1 0 1 0 1 0
// 0 1 1 1 1 0
// 0 0 1 1 1 0 
// 1 1 1 1 1 1 
//op- 9 (ie 3*3)

//dp[i][j]:rightmost bottom most cell of subsquare
//if(mat[i][j]==1) dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1])) + 1;
//else dp[i][j]=0 
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        
        vector<vector<int>> dp(matrix.size());
        dp.clear();
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                dp[i].push_back(0);
            }
        }
        
        int maxSz = 0;
        
        for(int i=0;i<matrix[0].size();i++)
        {
            dp[0][i] = matrix[0][i]-'0';
            if(dp[0][i]==1)maxSz=1;
        }   
        for(int j=0;j<matrix.size();j++)
        {
            dp[j][0] = matrix[j][0]-'0';
            if(dp[j][0]==1)
                maxSz =1;
        }   
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == '1')
                {   //dp[i][j]:rightmost bottom most cell of subsquare
                    dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1])) + 1;
                    maxSz = max(maxSz, dp[i][j]);
                }
            }
        }
        return maxSz*maxSz;
    
    }
};