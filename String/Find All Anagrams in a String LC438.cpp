class Solution {
public:
   
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        
        if(p.length() > s.length())
            return ans;
        
        unordered_map<char, int> table;
        for(char c: p)
            table[c]++;
        
        int begin = 0, end = 0, len = p.length();
        int count = table.size();
        
        while(end<s.length()){
            
            char endchar = s[end];
            if(table.find(endchar) != table.end()){
                
                table[endchar]--;
                if(table[endchar] == 0)
                    count--;
            }
            end++;
            
            while(count == 0){
                
                if(end - begin == len)
                    ans.push_back(begin);
                
                
                int startchar = s[begin];
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

// Similar to LC:76 Minimum Window Substring
