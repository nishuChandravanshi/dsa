			//BT TRAVERSALs : ITERATIVE--> T: O(n), S: O(n)

	//Pre-Order Traversal
vector <int> preorder(Node* root)
{
    if(root == NULL)
        return {root->data};
        
    vector<int>res;
    stack<Node*> st;
    st.push(root);
    
    while(!st.empty())
    {
        Node* curr = st.top();
        st.pop();
        
        res.push_back(curr->data);
        
        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
    }
    return res;
 
}


	//Post-Order Traversal
vector <int> postOrder(Node* root)
{
    if(root == NULL) return {};
    
    vector<int> res;
    stack<Node*> st;
    
    while(!st.empty() or root != NULL)
    {
        while(root != NULL){
            st.push(root);
            root = root->left;
        }
        
        Node *prev = NULL;
        
        while(root == NULL and !st.empty())
        {
            root = st.top();
            
            if(root->right == NULL or root->right == prev)
            {
                res.push_back(root->data);
                st.pop();
                prev = root;
                root = NULL;
            }
            else root = root->right;
            
        }
    }
    return res;
}

	//In-Order Traversal
vector<int> inOrder(Node* root)
{
 if(root == NULL) return {};
    
    vector<int> res;
    stack<Node*> st;
    
    while(!st.empty() or root != NULL)
    {
        while(root != NULL){
            st.push(root);
            root = root->left;
        }
        
        Node *curr = st.top();
        st.pop();
        
        res.push_back(curr->data);
        
        root = curr->right;
        
    }
    return res;
    
}
