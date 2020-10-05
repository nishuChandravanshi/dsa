
// @do it urself!!
//https://www.geeksforgeeks.org/program-nth-catalan-number/
//recursive:
    // C0 = 1,
    // Cn+1 = sum(Ci*Cn-1) -> i=0 to n, for n>=0


// T(n)=\sum_{i=0}^{n-1}T(i)*T(n-i-1)  for  n>= 1;    
// The value of nth catalan number is exponential that makes the time complexity exponential.
//=> use dp

// Time Complexity: Time complexity of above implementation is O(n2)
// Using Binomial Coefficient 
// We can also use the below formula to find nth catalan number in O(n) time. 

// Cn=(1/n+1)*(2n binomial n)     

unsigned long int catalanDP(unsigned int n)
{
    unsigned long int catalan[n+1];
    catalan[0] = catalan[1] = 1;
 
    for (int i=2; i<=n; i++)
    {
        catalan[i] = 0;
        for (int j=0; j<i; j++)
            catalan[i] += catalan[j] * catalan[i-j-1];
    }
    return catalan[n];
}
 

*********************************
//n-matched Parentheses
// https://leetcode.com/problems/generate-parentheses/
//  n = 3,
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()" 
// ]

class Solution {
public:
    // int count =0;
    void solve(int l, int r, string str, vector<string>&res)
    {
        if(l==0 && r==0)
        {
            //count++; //give catalan number
            res.push_back(str);
            return;
        }
        if(l == 0)
            solve(l, r-1, str+")", res);
        else if(l==r)
            solve(l-1,r,str+"(", res);
        else if(l<r) //left open brackets
        {
            solve(l-1,r,str+"(",res);
            solve(l,r-1,str+")",res);
        }   
    }
    
    vector<string> generateParenthesis(int n) {
        string str;
        vector<string>res;
        solve(n,n,str,res);
        cout<<count<<endl;
        return res;
    }
};

/*
n=3
states:  l=number of left brackets, r=number of right brackets
    
    if l==0, => all left brackets have been used and we've only right brackets left(eg-> (0,3) '(((' => r-1=>(0,2)->'((()' )   
    if l==r, number of left bracket = number of right bracket => only left('(') bracket can be opened.
    if l<r,=> some left brackets are left available unclosed ie open (ie '(()' or '(' or ... ) then we have two choices->
        i.  l-1 -> adding '(' {ie '(()'--> '(()(' }
        ii. r-1 -> adding ')' {ie '(()'--> '(())' }

*/









