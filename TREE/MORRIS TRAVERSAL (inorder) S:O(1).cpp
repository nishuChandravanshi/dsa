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
    		//T:O(n) Space: O(1) ->MORRIS TRAVERSAL
    vector<int> inorderTraversal(TreeNode* root) {
     
        vector<int> res;
        TreeNode* curr = root;
        
        while(curr != NULL){
            
            if(curr->left == NULL){
                res.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* pre = curr->left;
                
                while(pre->right != NULL and pre->right != curr)
                {
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = curr;
                    curr = curr->left;
                }
                else{   //when pre->right == curr; ie left is already traversed so now again changing the links of tree nodes to origin node after storing the curr node 
                    pre->right = NULL;
                    
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        
        return res;
    }
};

/*idea->
-link inorder predecessor of curr to the curr node;
- Initialize current as root 
While current is not NULL
   If the current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Make current as the right child of the rightmost 
         node in current's left subtree
      b) Go to this left child, i.e., current = current->left
*/
