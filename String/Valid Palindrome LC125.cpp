class Solution {
public:
    
    bool isPalindrome( string s, int l, int r)
    {
        if(l == r) return true;
        
        while(l <= r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    /* recursive func 
    bool isPalindrome( string s, int l, int r)
    {
        if(l == r or l>r) 
            return true;

        return (s[l] == s[r]) and isPalindrome(s, l+1, r-1);
    }
    * memory limit exceeded for this func
    */

    bool isPalindrome(string s) {
        string str = "";
        
        int l = s.length();
        
        for(int i = 0; i < l; i++)
            if(isalnum(s[i]))
            {
                char ch = s[i];
                
                if(isupper(ch))
                    s[i] = tolower(ch);
                
                str += s[i];
            }        
      
        int n = str.length();
        return isPalindrome(str, 0, n-1);
    }
};
