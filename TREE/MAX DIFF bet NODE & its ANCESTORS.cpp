//MAX DIFF BETWEEN NODES AND ITS ANCESTOR'S
// https://www.geeksforgeeks.org/maximum-difference-between-node-and-its-ancestor-in-binary-tree/
// Input:
//       1
//     /    \
//    2      3
//            \
//             7
// Output: -1 (1-2)

int findMinNode(Node* node, int &ans) //findMinNode(root)=> returns smallest node of tree (rooted with root 
{
    if(node == NULL)
        return INT_MAX;
    if(node->left==NULL && node->right == NULL)
        return node->data;
    
    int minVal = min(findMinNode(node->left,ans), findMinNode(node->right,ans));
    
    ans = max(ans, node->data - minVal);
    
    return min(node->data, minVal);
}
int maxDiff(Node* root)
{
    int ans = INT_MIN;
    findMinNode(root,ans);
    return ans;
}
