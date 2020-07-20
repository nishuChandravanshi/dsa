
Node *inOrderSuccessor(Node *root, Node *x)
{
    if(root == NULL or x == NULL) return NULL;

    
    if(x->right != NULL)
    {
        Node *prev = x->right; //to get leftmost of right subtree
        
        while(prev->left != NULL)
            prev = prev->left;
        
        return prev;
    }
    else
    {
        Node *curr = root, *succ = NULL;
        while(curr != x){
            if(curr->data > x->data) //x is left child => root can be succ
            {
                succ = curr;
                curr = curr->left;
            }
            else if(curr->data < x->data)
                curr = curr->right;
            
            else break;
        }
        return succ;
    }
    
    return NULL;
}


/*
    T: O(h), S: O(1)
If right subtree of node is not NULL 
    - then successor is the leftmost child of node's right subtree
else 
    -if node is the left child of its parent then parent is the succ
    (ie consider node is the right most(or last node in left subtree) of its parent left subtree)
    else (ie node is in right child of its parent => succ is that ancestor of node for which it is the left child)

**when traversing from root- we are basically looking for the node(which'll be ancestor) whose left subtree's rightmost child is our given node
        
*/
