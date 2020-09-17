0 1 0 0 1    Rooms: 5
1 0 0 0 1
0 1 1 1 1
1 0 0 1 0

void countRoomsHelper(int i, int j, vector<vector<int>> &v)
{
    if(i >= v.size() or j >= v[0].size() or i < 0 or j < 0)
        return ;
    if(v[i][j] == 1)
        return;
    if(v[i][j] == 0)
    {
        v[i][j] = 1;
        countRoomsHelper(i+1, j, v);
        countRoomsHelper(i-1, j, v);
        countRoomsHelper(i, j+1, v);
        countRoomsHelper(i, j-1, v);
    }
 
}

int countRooms(vector<vector<int>> &v)
{
    int n = v.size();
    if(n == 0) return 0;
    int m = v[0].size();

    int rooms = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            if(v[i][j] == 0){
                countRoomsHelper(0, 0, v);
                rooms++;
            }
    }
    
    return rooms;
}

//
A B 1.2   1 A = 1.2 B  => A/b = 1.2
B C 4.2
D E 8

Q queries:
A B 10 => 10 coins of A:: B?  10/1.2

float dfs(int src,int dest, vector<pair<int, float>> g[n], vector<bool> &visited, float factor)
{
    visited[src] = true;
    
    if(src == dest)
        return factor;
    
    for(auto to : g[src])
    {
        if(!visited[to.first])
        {
            int child = to.first;
            float childFact = to.second;

            return dfs(child,dest, g, visited, factor*(1/childFact));
        }

    }

}

vector<float> conversion(vector<pair<pair<char, char>, int>> &v, vector<pair<pair<char, char>, int>> &queries)
{
    
    vector<pair<int, float>> g[n];
    
    for(int i = 0; i < v.size(); i++)
    {
        g[v[i].first.first - 'A'].push_back({v[i].first.second, v[i].second});
        g[v[i].first.second - 'A'].push_back({v[i].first.first, 1/v[i].second});
    }

    vector<float>res;
    for(int i = 0; i < queries.size(); i++)
    {
        int src = queries[i].first.first;
        int dest = queries[i].first.seccond;
        int coins = queries[i].second;
        vector<bool> visited(n,0);
        float factor = dfs(src,dest, g, visited,1);

        res.push_back(factor);
    }
    
    
    return res;
    
}

//merge,quick->ll

//kth max in stream
vector<int> kthMax(vector<int> v,int k)
{
    if(k == 1)
        return v;
    
    vector<int>res;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i = 0; i<k; i++)
        pq.push({v[i],i});

    res.push_back(pq.top().first);
    int start = 1;
    for(int i = k; i < v.size(); i++)
    {
        while(!pq.empty() && pq.top().second < start)
            pq.pop();

        pq.push({v[i],i});

        res.push_back(pq.top().first);
        start++;
    }
    return res;

}

//max in every window of size k
vector<int> kthMax(vector<int> v,int k)
{
    if(k == 1) return v;

    vector<int> res;
    dequeue<int> dq;
    for(int i = 0; i<v.size(); i++)
    {
        if(!dq.empty())
            dq.push_back(i);
        else if(v[i] <= v[dq.back()])
            dq.push_back(i);
        else 
        {
            while(!dp.empty() && v[i] > v[dq.back()])
                dq.pop_back();
            dq.push_back(i);

        }
        while(!dq.empty() && dp.front() < i-k+1)
            dq.pop_front();

        if(i >= k-1)
            res.push_back(v[dq.front()]);
    }     

}


//

node* first = NULL;
node* lca(node* root, node* a, node* b)
{
    if(root == NULL) return NULL;

    if(root == a)
        return a;
    if(root == b)
        return b;
    
    node* left = lca(root->left, a, b);
    node* right = lca(root->right, a, b);

    if(left && right) return root;
    
    return  left ? left : right;
}

bool cInPath(node* l, node* c, node* a, node* b)
{
    if(l == NULL)
        return false;

    if(l == a)
        first = a;
    else if(l == b)
        first = b;
    if( l == c)
    {
        if(first == NULL) first = c;
        return true;
    }
        
    
    bool left = cInPath(l->left, c, a, b);
    bool right = cInPath(l->right, c, a, b);

    return left || right;
}


node* deleteNode(node* root, node* a, node* b, node* c)
{
    node* l0 = lca(root, a, b);

    bool cInPath = inPath(l0, c, a, b);
    if(cInPath == false)
        return l0;
    else{
        return first; 
    }

}



//1.
words -> ["abc", "abde", "umbrella", "tummy", "uml"]

class PrefixSum

insertKey: args->str, value(int)   returns->None

prefixSum: args->str,  returns->(int) sum of values of all the strings with given prefix


abc -> a, ab ,abc  
a  

abdefgh-> a,ab,abd,abde,

//space: O(n*m^2) : n=no of words, m = length of str
class PrefixSum{
    unordered_map<string, int>mp; 

    void insertKey(string str, int val)
    {
        string pref = "";
        for(int i=0;i<str.length();i++)
        {
            pref += str[i]; //O(strlen)
            if(mp.find(pref) != mp.end())
                mp[pref] += val;
            else mp[pref] = val;
        }
    }

    int preSum(string pre)
    {
        if(mp.find(pre)!= mp.end()) //letter by letter check to find in map=> O(len(pre))
            return mp[pre];
        
        return -1;
    }

};


//string - immutable object->modification of string => creation of new string
//concatenation -> O(length of string)


words -> ["abc", "abde", "umbrella", "tummy", "uml"]

class PrefixSum

insertKey: args->str, value(int)   returns->None
prefixSum: args->str,  returns->(int) sum of values of all the strings with given prefix


class Trie {
    public:
        int nodeVal;
        unordered_map<char, Trie*>children;

    Trie(int val) {
        nodeVal = val;
    }

};

void insertWord(Trie* root, string word, int val) {
    for(auto letter: word) {
        if(root->children.find(letter)==root->children.end()) { //create and insert
            Trie* newNode = new Trie(val); //create
            root->children[letter] = newNode; //insert
            root = newNode; //shift
        }
        else {
            root->nodeVal += val; //update
            root = root->children[letter]; //shift
        }
    }
}

int findByPrefix(Trie* root, string pref) {
    int res;
    for(auto letter: pref) {
        if(root->children.find(letter)==root->children.end())
            return -1;

        root = root->children[letter];
        res = root->val;  
    }
    return res;
}

Trie* root = new Trie(0);
insertWord(root, "abc", 12);
insertWord(root, "abc", 12);
insertWord(root, "abc", 12);
cout<<findByPrefix(root, "az");



//3. rearrange string st no two adjacent characters are same
// rearrange -> no adj char same

aaabbbccddeee
abacabade

string solve(string str)
{
    vector<int>freq(26,0);

    for(int i=0; i<str.length();i++)
    {
        freq[str[i] - 'a']++;
    }
    priority_queue<pair<int,char>> pq;

    for(int i=0;i<26;i++)
    {
        if(freq[i]>=1)
            pq.push({freq[i],a + i});
    }

    string res = "";
// aaaaabbcdde
//aaz -> zaa (x) -->aza(crrct)  
    pair<int,char>temp;
    while(!pq.empty())
    {
        pair<char,int> curr = pq.top();
        pq.pop();

        if(temp.second >= 1)
            pq.push(temp);
    
        res += curr.first;
        curr.second -= 1;

        temp = curr;
    }
    if(str.length()!= res.length())
        return "";
    
    return res;
}


// todo
//uordered map : adv/disadv


//
// radix,bucket,counting(code)


//quick sort
0 1 2 3 4 0 5 6
1 1 1 3 4 5 6 1 2 -> 1 1 1 2 2 3 4   
4 1 1 1 
int partition(int l, int h, vector<int>&arr)
{
    int ind = l-1;
    for(int i=l;i<=h-1;i++)
    {
        if(arr[i]<=arr[h])
        {
            ind++;
            swap(arr[ind],arr[i]);
        }
    }
    swap(arr[h],arr[ind+1]);
    return ind+1;
}

void quickSort(int l, int h, vector<int>&arr)
{
    if(l>h)return;
    int pivot = partition(l,h,arr);
    quickSort(l,pivot-1,arr);
    quickSort(pivot+1,h,arr);
}

void quicksort(vector<int>arr)
{
    int n = arr.size();
    quickSort(0,n-1,arr);
}

// avg&best- nlogn, wrst- n^2

*********************************************************
//NEXT GREATER NODE IN BST
//l,r,parent
Node* nextGreater(Node* node)
{
    if(node==NULL)  return NULL;

    if(node->right != NULL)
    {
        Node* temp = node->right;
        
        while(temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
    else if(node->parent != NULL){
        Node* parentNode = node->parent;
        Node* temp = node;
        while(parentNode!= NULL && parentNode->left != temp)
        {
            Node* p = parentNode;
            parentNode = parentNode->parent;
            temp = p;
        }
        return parentNode;
    }
    else{
        return NULL;
    }
}


//
// maximum sum of any path
// 
        10
        / \
      -6   9
           
int maxSumPath(TreeNode* root, int &res)
    {
        if(root == NULL)
            return 0;
        //loop and find max two children pathSum of n-ary tree;
        int left = maxSumPath(root->left, res);
        int right = maxSumPath(root->right, res);

        int temp = max(left,right)+root->val;
        
        res = max(res, max(temp, max(left+right+root->val,root->val)));
        
        return max(temp,root->val);
    }


    int maxPathSum(TreeNode* root) {
        if(root == NULL) return INT_MIN;
        int res = INT_MIN;
        maxSumPath(root, res);
     return res;
    }


//array of books
// 1. fiction -> f, 2. non-fic-> n
//todo-> seperate 1 & 2 : in min swaps
// curr order given

arr {f,f,n,f,n,f}
int seperate(vector<char> arr)
{
    int n= arr.size();

    int nf = 0, nn=0;
    for(int i =0;<n;i++)
    {
        if(arr[i] == 'f')
            nf++;
        else nn++;
    }
    int steps1 =0,steps2=0;
    for(int i=0;i<nf;i++)
    {
        if(arr[i] != 'f')
            steps1++;
    }
    for(int i=0;i<nn;i++)
    {
        if(arr[i] != 'n')
            steps2++;
    }
    return min(steps1,steps2);
}


//INVERSION COUNT
int merge(int l, int mid, int r, vector<int>&arr)
{
    vector<int> temp(r-l+1);
    int count =0;

    int i = l, r = mid+1,t=0;

    while(i<=mid && j<=r)
    {
        if(arr[i] <= arr[j])
        {
            temp[t++] = arr[i++];
        }
        else{
            count += mid-i+1; //not mid-i+1 cuz-> we are considering pairs of a[i]>a[j] for i<j => from i to mid there'll be mid-i pairs {ie }
            temp[t++] = arr[j++];
        }
    }
    while(i<=mid)
    {
        temp[t++] = arr[i++];
    }
    while(j<=r)
    {
        temp[t++] = arr[j++];
    }
    t =0;
    for(int i=l;i<=r;i++)
    {
        arr[i]= temp[t++];
    }
    return count;
}

int mergesort(int l, int r, vector<int>&arr)
{
    if(l>=r) return 0;

    int mid = (l+r)/2;
    int ans =0;
    ans += mergesort(l, mid, arr);
    ans += mergesort(mid+1, r, arr);

    return ans + merge(l,mid,r,arr);
}

int inc(vector<int> arr)
{
    int r = arr.size()-1;
    return mergesort(0,r,arr);
}



//
//valid BST from preorder ->3:17


//Preorder ->BST
//Preorder ->validate BST
//postOrder (above two)
//levelorder + inorder ->binary tree
//preorder+inorder
//post + inorder


//Preorder -> validate BST
[8,4,3,5,10,9,12]

int nextGreater[n] = {n};
stack<pair<int, int>>s;
for(int i=0; i<n; i++) {
    while(!s.empty() && s.top().first<arr[i]) {
        nextGreater[s.top().second] = i;
        s.pop();
    }
    s.push({arr[i], i});
}

bool isValidBST(vector<int>&arr, int l, int h, int min, int max) {
    if(l>h) //null node
        return true;
    
    int root = arr[l];
    if(root<min || root>max)
        return false;

    //left subtree
    return isValidBST(arr, l+1, nextGreater[l]-1, min, root) && isValidBST(arr, nextGreater[l], h, root, max);
}

//create BST from preorder
Node* createBST(vector<int>&arr, int l, int h) {
    if(l>h)
        return null;

    Node* root = new Node(arr[l]);
    root->left = createBST(arr, l+1, nextGreater[l]-1);
    root->right = createBST(arr, nextGreater[l], h);
}



                1
            2       7
        9       
    5       6   


//BT FROM LEVEL ORDER AND INORDER

#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		int val;
		Node* left;
		Node* right;
	
		Node(int x) {
			val = x;
		}
};


inorder [5,9,6,2,1,7]
levelorder = [1,2,7,9,5,6]

levelIndices = [4, 3, 5, 1, 0, 2]

Node* createBTree(vector<int>&inorder, vector<int>&levelorder, vector<int>&levelIndices, int rootVal, int l, int h) {
    if(l>h)
        return NULL;

    Node* root = new Node(rootVal);
    
    if(l==h)
    	return root;
    	
    int rootIndex;
    for(int i=l; i<h; i++) {
        if(inorder[i]==rootVal) {
            rootIndex = i;
            break;
        }
    }

    //left subtree -> [l, rootIndex-1]
    int leftRootIndex;
    int curr = INT_MAX;
    for(int i=l; i<rootIndex; i++) {
    	if(curr>levelIndices[i]) {
    		leftRootIndex = i;
            curr = levelIndices[i]
    	}
    }

    root->left = createBTree(inorder, levelorder, levelIndices, inorder[leftRootIndex], l, rootIndex-1);

    //right subtree -> [rootIndex+1, h]

    int rightRootIndex;
    curr = INT_MAX;
    for(int i=rootIndex+1; i<=h; i++) {
    	if(curr>levelIndices[i])
    		rightRootIndex = i;
        curr = min(rightRootIndex, levelIndices[i]);
    }
    root->right = createBTree(inorder, levelorder, levelIndices, inorder[rightRootIndex], rootIndex+1, h);
    
    return root;
}

void printTree(Node* root) {
	if(root==NULL)
		return;
	
	cout<<root->val<<" ";
	printTree(root->left);
	printTree(root->right);
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int>levelorder(n);
	vector<int>inorder(n);
	
	for(int i=0; i<n; i++)
		cin>>inorder[i];
	
	for(int i=0; i<n; i++)
		cin>>levelorder[i];
	
	vector<int>levelIndices(n);
	for(int i=0; i<n; i++) {
	    for(int j=0; i<n; i++) {
	        if(inorder[i]==levelorder[j]) {
	            levelIndices[i] = j;
	        }
	    }
	}
	
	Node* root = createBTree(inorder, levelorder, levelIndices, levelorder[0], 0, n-1);
	cout<<"print preorder\n";
	printTree(root);
	
	return 0;
}