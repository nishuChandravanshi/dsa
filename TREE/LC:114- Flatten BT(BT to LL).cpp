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
 */ //tt-40min(trackImprovementNextTime)
class Solution {
public:
    void flatten(TreeNode* root) {
        
        if(root == NULL or (root->left == NULL and root->right == NULL))
            return;
        
        if(root->left)
        {
            flatten(root->left);
            
            TreeNode *rightSubTree = root->right;   //*
            
            root->right = root->left;
            root->left = NULL;
            
            TreeNode* tright = root->right;
            while(tright->right)
                tright = tright->right;
            
            tright->right = rightSubTree;                
            
        }
        
        flatten(root->right);
        
    }
};

/*
idea-
-if(root->left is NULL) then flatten root->right;
else
-first flatten the right subtree of the left most child of root
    1           
   / \              
  2   5                 
 / \   \                    
3   4   6                   
\                           
 8                      
 /                          
 9                          
here recursive call is as -( s => call stack)
                            1->2->3->8
(when we call 3 we encounter its left child is null so we go for its right subtre here 8)
now 8 has left child => 
                           s : 1->2->3->8->9 

(now as 9 is leaf node=>return to 8)
                           s :  1->2->3->8
Now //* section will be executed 
ie  root -->8
    
    rightSubtree = 8->right (=NULL)
   
    8->right = 9
    8->left = NULL

now go to the rightmost of 8 so as to add the initial right subtree of add to it after modification
then -
    8->9->(rightSubtree)
                          s : 1->2->3
3                   
\                           
 8                      
 \                          
  9                       
                        
1->2->3->8->9->null

*move ahead like this
                            
*/
