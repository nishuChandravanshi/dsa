//SUDOKU : T:O(9^(9*9))--> but much better than brute force
//as via backtracking a lot of prunings will be there before hand

// https://leetcode.com/problems/sudoku-solver/
class Solution {
public:
    bool isSafe(int row, int column, char num, vector<vector<char>>&board)
    {
        for(int i = 0;i<9;i++)
        {
            if(board[i][column] == num)
                return false;
        }
        for(int i=0;i<9;i++)
        {
            if(board[row][i] == num)
                return false;
        }
        int browStart = row-row%3; //getting the starting indices of the box they(row,column) belongs
        int bcolumnStart = column-column%3;
        for(int i = 0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[browStart+i][bcolumnStart+j] == num)
                    return false;
            }
        }
        return true;
    }
    
    bool solve(int i,int j, vector<vector<char>>&board)
    {
        if(i==9)
            return true;
        if(j==9)
            return solve(i+1,0,board);
        if(board[i][j] != '.')
            return solve(i,j+1,board);
        
        for(char num='1';num<='9';num++)
        {
            if(isSafe(i,j,num,board))
            {
                board[i][j] = num;
                
                if(solve(i,j+1,board))
                    return true;

                board[i][j]='.'; //backtracking
            }
        }
        return false;    
    }

    void solveSudoku(vector<vector<char>>& board) {    
        solve(0,0,board);
    }
};

/*
Brute Force:
    generate all boards (9^81)
    validate all boards
    return valid board
    
Backtracking:
    place 1-9 in each empty cell st
        it doesnt violate the constraints
    fill the board
*/


