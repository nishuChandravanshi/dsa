/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//T:O(n) -- calc ht in same recursive func-by passing ht by reference
class Solution {
public:         
    bool isBalanced(TreeNode* root, int &height)
    {
        if(root == NULL)
            return true;
        
        int lh = 0, rh = 0; //ht of left and right subtrees resp
        
        int leftBalance = isBalanced(root->left, lh);
        int rightBalance = isBalanced(root->right, rh);
        
        //ht of curr node
        height = max(lh, rh) + 1;
        
        if(abs(lh - rh) >= 2)
            return false;
        
        return leftBalance && rightBalance;
        
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL or (root->left == NULL and root->right == NULL)) 
            return true;
        
        int height = 0;
        
        return isBalanced(root, height);
    }
};



//T:O(n^2) - as ht of each node is calculated with the help of height func
class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        
        return 1+ max(height(root->left), height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        return ((abs(lh-rh)<=1 and
                 isBalanced(root->left) and 
                 isBalanced(root->right)));
        
    }
};

/*
Ques- https://leetcode.com/problems/balanced-binary-tree/
ip-    1	op - false
      / \
     2   2
    / \
   3   3
  / \
 4   4

ip- 3		op - true
   / \
  9  20
    /  \
   15   7
*/
