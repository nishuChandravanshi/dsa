#include <bits/stdc++.h>
using namespace std;

int canRearrange(string str)
{
    vector<int> freq(26,0);
    int n = str.length();
    
    for(int i = 0; i < str.length(); i++)
        freq[str[i] - 'a']++;
    
    priority_queue<pair<int, char> > pq;
    
    //by default maxheap is created ordered by first elemen of pair
    for(char c = 'a'; c <= 'z'; c++)
        if(freq[c-'a'])
            pq.push({freq[c-'a'], c});
    
    str.clear();
    
    //to keep track of prev char in arranged string
    pair<int, char> prev = {-1, '#'};
    
    while(!pq.empty())
    {
        pair<int, char> curr = pq.top();
        
        str += curr.second;     //curr added after prev{ensuring curr and prev chars are diff}
        curr.first--;
        
        pq.pop();
        
        if(prev.first > 0)
            pq.push(prev);
            
        prev = curr;
    }
    if(str.length() != n)
        return 0;
    return 1;
}

int main() {
    int t; cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        
        cout<<canRearrange(str)<<endl;
    }
    return 0;
}

/*
            T: O(nlogn) S: O(1){as 26 chars<->const}

https://practice.geeksforgeeks.org/problems/rearrange-characters/0
Q: Rearrange characters in a string such that no two adjacent characters are same.

ip- geeksforgeeks   op- 1
ip- bbbabaaacd      op- 1  
ip- bbbbb           op- 0
idea- 
-pq with basis of frequency of the char => char with higher freq on top of pq
-temporarily pop (to ensure that same char aint repeated agn)
the top of pq, add its char in the string(new str), reduce the char's frequence
-if prev char has freq > 0 => push it back into pq after adding curr char into string
- at last if original string length and arranged string length aint equal then its
not possible to form an arrangement without adjacent duplicates chars so return 0 else return 1;
*/
