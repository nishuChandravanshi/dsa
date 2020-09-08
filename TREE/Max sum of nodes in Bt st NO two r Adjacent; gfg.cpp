// https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/

#include<bits/stdc++.h> 
using namespace std; 
  
class Node 
{ 
public: 
    int data; 
    Node* left, *right; 
    Node(int data) 
    { 
        this->data = data; 
        left = NULL; 
        right = NULL; 
    } 
}; 
  
//  
pair<int, int> maxSum(Node* root)
{
	if(root == NULL) 
		return {0,0};
		
	pair<int, int> l = maxSum(root->left);
	pair<int, int> r = maxSum(root->right);
	
	pair<int, int> curr = make_pair(0,0);
	//taken, notTaken resp
	curr.first = root->data + l.second + r.second;
	curr.second = max(l.first, l.second) + max(r.first, r.second);
	
	return curr;
}


int maxSumFun(Node* root)
{
	//pair-> rootTaken, rootNotTaken
	pair<int, int> res = maxSum(root);
	return max(res.first, res.second);
}


int main() 
{ 
    Node *root= new Node(10); 
    root->left= new Node(1); 
    root->left->left= new Node(2); 
    root->left->left->left= new Node(1); 
    root->left->right= new Node(3); 
    root->left->right->left= new Node(4); 
    root->left->right->right= new Node(5); 
    cout << maxSumFun(root); 
    return 0; 
} 

/*
	T: O(n)
idea-
- storing the sum taking root node and not taking it in max sum resp, in pair
-
/
