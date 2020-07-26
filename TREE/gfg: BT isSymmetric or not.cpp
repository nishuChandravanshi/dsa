bool isSymmetric(Node* root1, Node* root2)
{
    if( root1 == NULL and root2 == NULL) 
        return true;
    
    if((root1 != NULL and root2 == NULL) or (root1 == NULL and root2 != NULL))
        return false;
    if(root1->data != root2->data) return false;
    
    return (root1->data == root2->data) and
            isSymmetric(root1->left, root2->right);
        
}

bool isSymmetric(struct Node* root)
{
    if(root == NULL) return true;
    
    if(root->left == NULL and root->right == NULL)
        return true;

    return isSymmetric(root, root);
}

/*  T:O(n)
-to check if tree is mirror image of itself of not
 ip          5
           /   \
          1     1
         /       \
        2         2
op- true
ip          5
          /    \
        10      20
      /    \      \
    20     20      30
op - false

*/
