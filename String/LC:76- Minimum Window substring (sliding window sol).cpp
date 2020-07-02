class Solution {
public:    
    string minWindow(string s, string t) {
        if(t.length() > s.length())
            return "";
            
        unordered_map<char, int> table;
        
        for(char c: t)
            table[c]++;
        
        int begin = 0,end = 0, len = INT_MAX;
        int count = table.size();
        string ans = "";
        
        while(end < s.length())
        {            
            char endchar = s[end];
            
            if(table.find(endchar) != table.end()){   
                table[endchar]--;
                if(table[endchar] == 0) count--;    
            }
            end++;
            
            //1
            while(count == 0)
            {
                if(end-begin < len){
                    len = end - begin;
                    ans = s.substr(begin, end-begin);
                }
                
                //2
                char startchar = s[begin];
                
                if(table.find(startchar) != table.end()){
                    
                    table[startchar]++;
                    if(table[startchar] > 0)
                        count++;
                }
                begin++;   
            }
            
        }
        
        
        return ans;
    }
};
/*T:O(n), S:O(n)
1- if count == 0, means we found an answer, now try to trim that window by sliding begin to right.
2- if char at begin of prev window is not part of T then simply move to next char by moving begin right side, else update the table for char which will be required to form valid substr but is now being trimmed from begin of the prev window inorder to search for the new window

-->OTHER PROBLEMS THAT CAN BE SOLVED WITH SAME APPROACH-
(LC:)
438. Find All Anagrams in a String
30. Substring with Concatenation of All Words
3. Longest Substring Without Repeating Characters
159. Longest Substring with At Most Two Distinct Characters
567. Permutation in String
340. Longest Substring with At Most K Distinct Characters which is 
424. Longest Repeating Character Replacement
Reference- medium@csgator
 */
