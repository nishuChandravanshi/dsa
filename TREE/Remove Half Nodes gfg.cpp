Node *RemoveHalfNodes(Node *root)
{
    if(root == NULL) return NULL;
    
    root->left = RemoveHalfNodes(root->left);
    root->right = RemoveHalfNodes(root->right);
    
    if(root->left == NULL and root->right == NULL)
        return root;
    
    if(root->left == NULL) //free(root)
        return root->right;
 
   if(root->right == NULL)
        return root->left;
    
    return root;
    
}
