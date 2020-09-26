bool isIsomorphic(Node *root1,Node *root2)
{
    if(root1 == NULL and root2 == NULL) 
        return true;
    if(root1 == NULL or root2 == NULL)
        return false;
    
    if(root1->data != root2->data)
        return false;
    
    return (isIsomorphic(root1->left, root2->left) and isIsomorphic(root1->right, root2->right))
    or (isIsomorphic(root1->left, root2->right) and isIsomorphic(root1->right, root2->left));
}

/*
    T: O(min(m,n)) {m,n=>no of nodes in root1 and root2}
ip- 
root1:   1
        / \     
       2   3
      / \  /
     4  5  6
       / \
      7   8
      
root2:   1
        / \     
        3   2  
         \ / \
         6 4  5
             / \            
             8  7
op - true

idea-
two conditions for subtrees rooted with n1 and n2 to be isomorphic.
1) Data of n1 and n2 is same.
2) One of the following two is true for children of n1 and n2
    a) Left child of n1 is isomorphic to left child of n2 and right child of n1 is isomorphic to right child of n2.
    b) Left child of n1 is isomorphic to right child of n2 and right child of n1 is isomorphic to left child of n2.
    
*/
