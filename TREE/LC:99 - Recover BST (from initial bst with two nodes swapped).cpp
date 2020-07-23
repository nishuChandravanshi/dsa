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
			//T:O(n) (Single Pass), S:O(1)
class Solution {
public:
    void inorderTraversal(TreeNode* root, TreeNode **first, TreeNode **mid, TreeNode **last, TreeNode  **prev) //**-> for keeping address of the pointer type var (as these are already pointers)
    {
        if(root == NULL) return;
        
        inorderTraversal(root->left, first, mid, last, prev);
       
        if( *prev and root->val < (*prev)->val)
        {
           if(! *first)
           {
               *first = *prev;
               *mid = root;
           }
            else
                *last = root;
            
        }
        *prev = root;
        
        if(*first and *last) return;
        
        inorderTraversal(root->right, first, mid, last, prev);
        
    }
    
    void recoverTree(TreeNode* root) {

        if(root == NULL or (root->left == NULL and root->right == NULL)) return;
        
        TreeNode *prev, *first, *mid, *last;
        prev = first = mid = last = NULL;
        
        inorderTraversal(root, &first, &mid, &last, &prev); //passing addr of pointer so as the changes made by the func must be reflected in the original pointers as well
        
        if(first and last)
            swap(first->val, last->val);
        else if(first and mid)
            swap(first->val, mid->val);
 
    }
};

/*  T:O(n) (Single Pass)
    idea- inorder of bst => sorted
    The inorder of given bst there can be either two or one point where sort will be violated
    -two points where curr is less than prev => two non adjacent nodes swapped --> making first point to the prev node and last will then point to next node which for which we'll encounter curr < prev
    -only one such point => two adjacent nodes are swapped-->first will point to prev and middle will point to curr and these two will be the required nodes (in this case last will remain NULLs)

*/



/*		//T:O(n), S:O(n)
class Solution {
public:
    void inorderTraversal(TreeNode* root, vector<int>& inorder, bool& toModify, int &index)
    {
        if(root == NULL) return;
        
        if(root->left) inorderTraversal(root->left, inorder, toModify, index);
       
        if(!toModify ) inorder.push_back(root->val);
        else{
            if(index < inorder.size() and root->val != inorder[index])
                root->val = inorder[index];
            index++;
        }
        
        if(root->right) inorderTraversal(root->right, inorder, toModify, index);
        
    }
    
    void recoverTree(TreeNode* root) {

        if(root == NULL or (root->left == NULL and root->right == NULL)) return;
        
        vector<int> inorder;
        inorder.push_back(INT_MIN); //so as to avoid condition when first index is swapped then first will become 0.
        
        bool toModify = false;
        int index = 1;
        
        inorderTraversal(root, inorder, toModify,index);
        
        int first = 0, second = 0;  //frst and scnd will point to the swapped nodes in inorder.
        
        for(int i = 1; i < inorder.size() - 1; i++){
            
            if(!first and inorder[i+1] < inorder[i])
                first = i;
            
            else if(first and !second and inorder[i+1] < inorder[i])
                second = i+1;
            
            if(first and second) break;
                
        }

        if(first and second)
            swap(inorder[first], inorder[second]);
        else if(first and !second)
            if(first + 1 < inorder.size()) swap(inorder[first], inorder[first + 1]);
        
        toModify = true;
        
        inorderTraversal(root, inorder, toModify, index); //as inorder contains values from index 1
        
    }
};
*/
/*  T:O(n), S:O(n)
    idea- inorder of bst => sorted
    The inorder of given bst there can be either two or one point where sort will be violated
    -two points where curr is less than prev => two non adjacent nodes swapped
    -only one such point => two adjacent nodes are swapped

*/
