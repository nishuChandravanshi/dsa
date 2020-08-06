class Solution {
public:
    int findMaxArea(vector<int> v)
    {
        stack<int> st;
        int n = v.size();
        int i = 0;
        
        int currArea = 0; //contain ar with top as smallest
        int maxArea = 0;
        while(i < n)
        {
            if(st.empty() or v[i] > v[st.top()])
                st.push(i++);
            else{
                int top = st.top();
                st.pop();
                
                currArea = (v[top])*(st.empty() ? i : (i - st.top() -1));
                maxArea = max(maxArea, currArea);
            }
        }
        while(!st.empty())
        {
            int top = st.top();
            st.pop();
            currArea = (v[top])*(st.empty() ? i : (i - st.top() - 1));
            maxArea = max(maxArea, currArea);
            
        }
        
     return maxArea;   
    }
        
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.size() == 1 and matrix[0].size() == 1)
            return matrix[0][0]-'0';
        
        //modify matrix
        vector<vector<int>> matrix1(matrix.size());
        
        for(int i = 0; i < matrix1.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == '0')
                    matrix1[i].push_back(matrix[i][j]-'0');
                else{
                    if(i > 0)
                        matrix1[i].push_back(matrix1[i-1][j] + 1);
                    else
                        matrix1[i].push_back(matrix[i][j] - '0'); 
                }
            }

        
        int maxRow = 0;
        int maxArea = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            maxRow = findMaxArea(matrix1[i]);
            maxArea = max(maxArea, maxRow);
        }
        
        return maxArea;
    }
};

/*
    T: O(mxn), S: O(mxn) + O(n){as stack for columns}
	NOTE: here S(m*n) because initially char matrix was given and we needed to convert it into int and store it in new int matrix(matrix1)

problem: LC:85
Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6

algo-->
row1- "1","0","1","0","0" : maxArea = 1
row2- "2","0","2","1","1" : maxArea = 3
row3- "3","1","3","2","2" : maxArea = 6
row4- "4","0","0","3","0" : maxArea = 6

*--> "0" in any cell will remain "0" even after modification of that row : as we want max area of continuous rectangle and 0s are the point of discontinuity so must be preserve(or simply imagine vertical heights as in histogram) 


idea-
-consider each row as histogram and find largest rect in that row
-update next row and do the same as in 1st step 
-continue as above for rest of the rows

*/
