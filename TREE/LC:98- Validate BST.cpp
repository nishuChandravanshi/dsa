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
class Solution {
public:
    bool isBst(TreeNode* root, long left, long right)
    {
        if(root == NULL)
            return true;
        
        if((root->val <= left) or (root->val >= right))
            return false;
            
        return isBst(root->left, left, root->val) and
               isBst(root->right, root->val, right);
    }
    
    bool isValidBST(TreeNode* root) {
        if(root ==  NULL or (root->left == NULL and root->right == NULL))
            return true;
        
        return isBst(root, LONG_MIN, LONG_MAX);
        
    }
};

/*
i/p:     5
        / \
       1   4
          / \
         3   6
o/p-false

*/
