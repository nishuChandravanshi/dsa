/*
https://leetcode.com/problems/word-search/

-can move-> up down left right (ie horiz & vertically)

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/

class Solution {
public:
    int x[4] ={0,0,1,-1}; //for moves(directions)
    int y[4] ={1,-1,0,0};
    
    bool isValid(int i, int j, int ind, string &word, vector<vector<char>> &board)
    {
        if(i<0 or j<0 or i>=board.size() or j>= board[0].size() or word[ind]!=board[i][j])
            return false;
        return true;
    }
    
    bool dfs(int i, int j, int ind, string &word, vector<vector<char>> &board)
    {
        if(ind == word.length())
            return true;
        
        bool ans = false;
        
        if(isValid(i,j,ind,word,board))
        {
            board[i][j] = '*';
            for(int k=0;k<4;k++)
            {
                 ans = ans ||dfs(i+x[k],j+y[k],ind+1, word, board);
            }   
            board[i][j] = word[ind]; //back tracking. ie retrieving board[i][j](which was changed to '*')
            // cout<<board[i][j];
        }
        
        return ans; 
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        if(word.length()> n*m)
            return false;
        
        bool ans = false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == word[0])
                { 
                    // cout<<word[0]<<endl;
                    ans = ans || dfs(i,j,0,word,board);
                     cout<<endl;
                    if(ans == true)
                        break;
                }
            }
        }
        return ans;  
    }
};
