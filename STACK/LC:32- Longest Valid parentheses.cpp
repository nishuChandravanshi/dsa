class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() <= 1) return 0;
        
        stack<int> st;
        st.push(-1);    //as for () ->ind 0,1 => valid leng = 1-(-1){as after popping 0, when 1 is encountered}
        int mxValid = 0;
        int mxCurr = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
                st.push(i);
            else{
                if(st.top() != -1 and s[st.top()] == '(')
                {
                    st.pop();
                    mxValid = max(mxValid, i-st.top());
                }
                else st.push(i);
                
            }
        }
        
        return mxValid;
    }
};

/*
        T: O(n), S: O(n)
Input: ")()())())"
Output: 4
idea-
-to keep track of the indexes where there can be violation of valid parenths, 
meanwhile updating the maximum length obtained so far

*/
