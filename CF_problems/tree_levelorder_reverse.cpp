/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>v;
        
        if(root==NULL)
            return {};
        else
       {
        int i=0;
       
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
          int s= q.size();
          vector<int>v1;
            while(s!=0)
          {
           TreeNode* p=q.front();
            
           v1.push_back(p->val);
           q.pop();
           if(p->left) q.push(p->left);
           if(p->right) q.push(p->right);
           s--;
          }
            v.push_back(v1);
          
        }
        std::reverse(v.begin(),v.end());
        
       }
       
        return v;
    }
};
