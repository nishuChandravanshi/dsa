
//NO. OF PALINDROMIC PATHS
// https://practice.geeksforgeeks.org/problems/number-of-palindromic-paths-in-a-matrix/0
//recursive : T:exponential; O(2^(r*c)) 
int palindromicPath(int i, int j, string str, vector<vector<char>> mat,int r,int c)
{
    if(i>=r or j>=c)
        return 0;
    else if(i==r-1 && j == c-1)
    {
        string temp = str;
        reverse(temp.begin(),temp.end());
        
        if(temp == str)
            return 1;
        else return 0;
    }
    int count = 0;
    if(i+1<r and j<c)
        count += palindromicPath(i+1,j,str+mat[i+1][j],mat,r,c);
    if(i<r and j+1 < c)
        count += palindromicPath(i,j+1,str+mat[i][j+1],mat,r,c);
    return count;
}

int main() {
    int t; cin>>t;
    while(t--)
    {
        int r,c; cin>>r>>c;
        vector<vector<char>> matrix(r);
        for(int i=0;i<r;i++)
        {
            for(int j =0;j<c;j++)
            {
                char a; cin>>a;
                matrix[i].push_back(a);
            }
        }
        //mp.clear(); //for dp
        string str(1,matrix[0][0]); //to convert char to string: using string class constructor str(size, char)
        cout<<palindromicPath(0,0,str,matrix,r,c)<<"\n";
    }
	return 0;
}

//dp O(r*c) : 

map<pair<pair<int,int>,string>, int>mp; // i,j,str->count

int palindromicPath(int i, int j, string str, vector<vector<char>> mat,int r,int c)
{
    if(i>=r or j>=c)
        return 0;
    else if(i==r-1 && j == c-1)
    {
        string temp = str;
        reverse(temp.begin(),temp.end());
        
        if(temp == str)
            return 1;
        else return 0;
    }
    if(mp.find({{i,j},str}) != mp.end())
        return mp[{{i,j},str}];
    
    
    int count = 0;
    if(i+1<r and j<c)
        count += palindromicPath(i+1,j,str+mat[i+1][j],mat,r,c);
    if(i<r and j+1 < c)
        count += palindromicPath(i,j+1,str+mat[i][j+1],mat,r,c);
    
    mp[{{i,j},str}] = count;
    
    return count;
}


/*
dp states - i,j,str
: if we're encountering same state which has been previously calculated we'll simply return
-here same state => if we get str for some [i][j] ( which is coming from different path), and that i,j,str we already calculated then we can simply return
eg.
3 4
a a a b
b a a a
a b b a
op-3
here-> 
reaching(2,1,abab from 2,0,aba):    2,0,aba -> 2,1,abab --- 2,3,ababba-> return 0;
& reaching(2,1,abab from 1,1,aba):  1,1,aba ->  2,1,abab --- 2,3,ababba-> return 0;

as we can see here: (2,1,abab) can be stored when encountered first time and then can be returned if agn encounterd, wt help of dp
Note* 2,1,anyt string other than abab will be a different state, and every state will be stored individually
*/
