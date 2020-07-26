
Node* buildTree(int in[], int pre[], int& preInd, int inS, int inE, map<int, int>& inorderPos)
{
    if(inS > inE)   //ins, inE=>starting and ending indices of inorder for respective roots   
        return NULL;
    
    Node *root = new Node(pre[preInd++]);
    
    if(inS == inE)  //=>leaf node
        return root;
    
    int rootInorderPos = inorderPos[root->data];
    
    root->left = buildTree(in, pre, preInd, inS, rootInorderPos - 1, inorderPos);
    root->right = buildTree(in, pre, preInd, rootInorderPos + 1 , inE, inorderPos);
    
    return root;
}

Node* buildTree(int in[],int pre[], int n)
{

    if(n == 1) 
        return new Node(in[0]);
        
    map<int, int> inorderPos;
    
    for(int i = 0; i < n; i++)
        inorderPos[in[i]] = i;
    
    int preInd = 0;
    return buildTree(in, pre, preInd, 0, n-1, inorderPos);
}

/*
    T: O(n), S; O(n)
-hashmap used to store the indexes of inorder traversal values
*/
