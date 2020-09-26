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
    void mapParent(TreeNode *root, map<TreeNode*, vector<TreeNode*>> &mp)
    {
        if(root == NULL) return;
        if(root->left){
            if(mp.find(root->left) == mp.end())
            mp[root->left] ={root, root->left->left, root->left->right};
        }
        if(root->right)
        { 
            if(mp.find( root->right) == mp.end())
                mp[root->right] ={root, root->right->left, root->right->right};

        }
        mapParent(root->left, mp);
        mapParent(root->right, mp);
        
    }
        
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
     
        if(K == 0) return {target->val};
        vector<int> res;
        
        map<TreeNode*, vector<TreeNode*>> mp;
        mp[root] ={NULL,root->left, root->right};
        
        mapParent(root,mp);
        
        queue<TreeNode*> q;
        q.push(mp[target][0]);
        q.push(mp[target][1]);
        q.push(mp[target][2]);
        K--;
        
        set<TreeNode*> visited;
        visited.insert(target);
        visited.insert(mp[target][0]);
        visited.insert(mp[target][1]);
        visited.insert(mp[target][2]);
        
        
        while(!q.empty())
        {
            int levelSize = q.size();
            
            if(K)
                while(levelSize--)
                {
                    TreeNode* curr = q.front();
                    q.pop();
                    
                    for(auto it : mp[curr]){
                        if(visited.find(it) == visited.end())
                        {
                            q.push(it);
                            visited.insert(it);
                        }
                    }
                } 
            if(K)K--;
            
            if(K == 0 )
                while(!q.empty())
                {
                    if(q.front())res.push_back(q.front()->val);
                    q.pop();
                }
        }
        
        return res;
    }
};

//WELL DONE!!love ya:>>
/*
idea
- to do bfs from the target node
-for that keeping record of parents, inorder to traverse upper level from target
*/
