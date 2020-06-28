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
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        
        stack<TreeNode*>st;
        map<TreeNode*,  TreeNode*> parent;        
        int totalPathSum=0;
        
        st.push(root);
        parent[root]=NULL;
        
        while(!st.empty()){
            TreeNode* curr=st.top();
            st.pop();
            
            //curr is leaf node=>traverse for path from                                                 curr to root through parent 
            if(!curr->left and !curr->right) 
            {
                int a=1,onePathSum=0;
                TreeNode* temp= curr;
                while(temp){
                    onePathSum=onePathSum+temp->val*a;
                    a*=10;
                    
                    temp=parent[temp];
                }
                
                totalPathSum+=onePathSum;
            }
            
            //right first in stack(so it'll be processed later) as we want                                  to process left before right
            if(curr->right) 
            {
                st.push(curr->right);
                parent[curr->right]=curr;
            }
            
            if(curr->left) 
            {
                st.push(curr->left);
                parent[curr->left]=curr;
            }
                
        }
        
        return totalPathSum;
    }
};
