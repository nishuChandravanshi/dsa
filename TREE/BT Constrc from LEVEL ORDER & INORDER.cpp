//* Construction of BT using INORDERE & LEVEL ORDER TRAVERSAL : T:O(n^2)
// https://www.geeksforgeeks.org/construct-tree-inorder-level-order-traversals/
//practice- https://practice.geeksforgeeks.org/problems/construct-tree-from-inorder-and-levelorder/1


//in:  3 1 4 0 5 2 6 
//lev: 0 1 2 3 4 5 6 
//op: 0 1 3 4 2 5 6
#include <bits/stdc++.h>
using namespace std;

struct Node{
	int val; 
	Node* left;
	Node* right;
	
	Node(int x)
	{
		val =x;
		left = NULL;
		right = NULL;
	}
};
map<int,int>inorderInd; //to store inorders index

Node* createBTree(int rootVal, int l, int h, vector<int>&levelIndices, vector<int>&levelorder, vector<int>&inorder)
{
	if(l>h)	return NULL;
	
	Node* root = new Node(rootVal);	
    if(l==h) return root;

	int rootInd = inorderInd[rootVal];
	
	// root->left: l to rootInd-1 & root->right: rootInd+1 to h
	//root->left node's val will be first node in level order of root->left's subtree ie the node with minimum levelIndices in root->left
	
	int curr = INT_MAX,leftRoot;
	for(int i=l;i<rootInd;i++)
	{	
		if(curr>levelIndices[i])
		{
			curr = levelIndices[i]; //choosing the first levelorder element among levelorder of root->left's element
			leftRoot = levelorder[curr];
		}
	}
	root->left = createBTree(leftRoot, l,rootInd-1,levelIndices, levelorder,inorder);
	
	curr=INT_MAX;
	int rightRoot;
	for(int i=rootInd+1;i<=h;i++)
	{
		if(curr>levelIndices[i])
		{
			curr = levelIndices[i]; 
			rightRoot = levelorder[curr];
		}
	}
	
	root->right = createBTree(rightRoot, rootInd+1, h,levelIndices, levelorder,inorder);
	
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
		inorderInd[inorder[i]] = i;
	    for(int j=0; j<n; j++) {
	        if(inorder[i]==levelorder[j]) {
	            levelIndices[i] = j; //levelorder pos of inorder[i] is j
	        }
	    }
	}
	
	Node* root = createBTree(levelorder[0], 0, n-1, levelIndices, levelorder,inorder);
	cout<<"print preorder\n";
	printTree(root);
	
	return 0;
}
