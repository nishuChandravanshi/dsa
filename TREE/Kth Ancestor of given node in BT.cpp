void mapParent(Node* root, map<Node*, Node*>& parent)
{
    if(root == NULL)
    {
        return;
    }
    
    if(root->left)
    {
        if(parent.find(root->left) == parent.end())
            parent[root->left] = root;
    }
    
    if(root->right)
    {
        if(parent.find(root->right) == parent.end())
            parent[root->right] = root;
    }
    
    mapParent(root->left, parent);
    mapParent(root->right, parent);
}

int kthAncestor(Node* root, int node, int k, map<Node*, Node*>& parent)
{
    Node* node1;    //*
    map<Node*, Node*> :: iterator it = parent.begin();
    
    while(it != parent.end())
    {
        if(it->first->data == node)
            node1 = it->first;
        it++;
    }
    
    
    while(k and  node1!= NULL)
    {
        node1 = parent[node1];
        k--;
    }
    if(node1 == NULL)
    return -1;
    
    return node1->data;
    
}

int kthAncestor(Node *root, int k, int node)
{
    if(root == NULL) return -1;
    if(root->data == node) return -1;
    
    map<Node*, Node*> parent;
    parent[root] = NULL;
    mapParent(root, parent);
    
    return kthAncestor(root, node, k, parent);
    
}


/*
	//* -> node1 is used to get to the node whose kth ancestor we want,
so as we would be able to traverse up from that node to the kth ancestor
(since the node initially given is only value and not the reference of the node,
we are obtainig the reference of the node(node1) with the help of parent
*/

/*
    T: O(n), S: O(n)
idea-
- child-parent mapping then
-find the reference of node
-traverse k upwards with the help of parent map, from node(reference:ob in 2nd step)
*/





// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}
// } Driver Code Ends

