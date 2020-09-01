
// https://leetcode.com/problems/wildcard-matching/submissions/

// s = "adceb"
// p = "*a*b"
// Output: true
// s = "acdcb"
// p = "a*c?b"
// Output: false

class Solution {
public:
    vector<vector<int>> dp;
    bool isValid(int i, int j, string &pat, string &str) //pass string by reference. Call by value->TLE.(as everytime entire val will be copied which leads O(n) time in every pass)
    {
        if(j == str.length() && i==pat.length())
            return true;
        else if(j==str.length()) // (str,pat): (a,a***)-true
        {
            while(i<pat.length() && pat[i]=='*')
                i++;
            if(i==pat.length())
                return true;
            return false;
        }
        else if(i>=pat.length() || j>=str.length())
            return false;

        if(dp[i][j]!=-1)
            return dp[i][j];

        bool ans = false;

        //recursion-->
        if(pat[i] == str[j] or pat[i] == '?')
            ans = ans || isValid(i+1,j+1,pat,str); //if same char or pat=?(any single char is allowed) => i+1,j+1 
        else if(pat[i] == '*')
            ans = isValid(i,j+1,pat,str)|| isValid(i+1,j,pat,str)|| isValid(i+1,j+1,pat,str);

        dp[i][j] = ans;
        return ans;
    }
    
    bool isMatch(string s, string p) {
        if((s.length()==0 && p.length()==0)or 
        (s.length()==0 and p.length()==1 and p[0]=='*')) 
            return true; //("",""), ("","*")
        
        dp.clear();
        for(int i=0;i<=p.length();i++)
        {
            vector<int>temp;
            for(int j=0;j<=s.length();j++)
            {
                temp.push_back(-1);
            }
                dp.push_back(temp);
        }
        return isValid(0,0,p,s);   
    }
};