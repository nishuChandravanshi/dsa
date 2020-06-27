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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inS, int inE, int &       postInd, map<int, int>& inorder_map){
        
        if(inS>inE)
            return NULL;
        
        TreeNode* tnode = new TreeNode(postorder[postInd--]);
        
        if(inS==inE)
            return tnode;
        
        int searchInd = inorder_map[tnode->val]; //index of tnode->val in inorder traversal
        
        tnode->right =  buildTree(inorder, postorder, searchInd+1, inE, postInd, inorder_map);
        tnode->left =  buildTree(inorder, postorder, inS, searchInd-1, postInd, inorder_map);
        
        return tnode;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len=inorder.size();
        if(len==0)
           return NULL;
        
        int postInd=len-1;
        map<int, int>inorder_map;
        for(int i=0;i<len;i++)
            inorder_map[inorder[i]]=i;
        
        return buildTree(inorder, postorder, 0, len-1, postInd, inorder_map);
    }
};
