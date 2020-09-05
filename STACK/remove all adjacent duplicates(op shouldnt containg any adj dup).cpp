// REMOVE ALL ADJACENT DUPS (final op should be free from adj duplicates)
// https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates/0

// geeksforgeek : gksforgk
// acaaabbbacdddd : acac
// mississipie : mpie
// 
int main() {
	//code
	int t;
	cin>>t;
	string maxi;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int n;
	    n=s.length();
	    stack<int> stack;
	    
	    label: 
	    stack.push(0);
	    for(int i=1;i<n;)
	    {
	        if(!stack.empty() and stack.top()+1 == i and s[stack.top()]==s[i] )
	        {
	            while(i< n and s[stack.top()]==s[i])
	            {
	                i++;
	            }
	            stack.pop();
	        }
	        else
	        {
	            stack.push(i);
	            i++;
	        }
	    }
	    
	    string l;
	    while(!stack.empty())
	    {
	        l.push_back(s[stack.top()]);
	        stack.pop();
	    }
	    reverse(l.begin(),l.end());
	    if(l==s)
	        cout<<l<<endl;
	    else
	    {
	        s= l;
	        n=l.length();
	        goto label;
	    }
	    
	}
	return 0;
}

// RECURSIVE
void removeDups(int &i, string &opstr, string &str)
{
    int n = str.length();
    //abcd
    // cout<<n<<endl;
    if(i >= n)
        return;
    //abbbbbc
    while(i<n-1 && str[i] == str[i+1])
        i++;
    if(i>=1 && str[i]==str[i-1]) //ie if above loop got executed then i will be pointing to last dup char(adjacent) so moving it to next.
    	i++;
    
    if(i>0 && i == n-1) //last char
    {
        if( str[i] != str[i-1])
            opstr += str[i];
        i++;
    }
        
    if(i<n-1 && str[i]!= str[i+1])
    {
        opstr += str[i++];
        // cout<<opstr<<endl;
    }
    return removeDups(i, opstr, str);    
    
}
int main() {
    int t; cin>>t;
    while(t--)
    {
        string str; cin>>str;
        string opstr ="";
        string newopstr = "";
        int ind = 0;
        if(str.length() == 1)
            cout<<str<<endl;
        else{
            while(true){
                // mississipie
                removeDups(ind,opstr,str);
    	        
    	        if(opstr == str)
    	        {
    	            break;
    	        }
    	        ind =0;
    	        str = opstr;
    	        opstr = "";
    	        
    	        removeDups(ind,opstr,str);
    	        
    	        if(opstr == str)
    	        {
    	            break;
    	        }
                ind = 0;
                str = opstr;
    	        opstr = "";
            }
	        cout<<str<<endl;	
        } 
    }
	return 0;
}