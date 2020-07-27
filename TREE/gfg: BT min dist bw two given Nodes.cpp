

Node* getLca(Node* root, int a, int b)
{
    if(root == NULL) return NULL;
    
    if(root->data == a or root->data == b)
        return root;
    
    Node* l = getLca(root->left, a, b);
    Node* r = getLca(root->right, a, b);
    
    if(l != NULL and r != NULL) return root;
    
    return l ? l : r;
}

int distFromLca(Node* source, int destination, int& dis)
{
    if(source == NULL) rturn INT_MIN;
    
    if(source->data == destination)
        return dis;
    
    return min(distFromLca(source->left, destination, dis),
    distFromLca(source->right, destination, dis));
    
}

int findDist(Node* root, int a, int b) {
    
    if(root == NULL) return -1;
    if(a == b) return 0;
    
    Node* lca = getLca(root, a, b);
    
    int lcaToADis = 0;
    distFromLca(lca, a, lcaToADis);
    int lcaToBDis = 0;
    distFromLca(lca, b,lcaToBDis);
    
    return lcaToADis + lcaToBDis;
}



/*
	T: O(n)

eg-	 1
	/ \
       2   3
      /	\  /\
     4  5 6  7
           \
	    8

dis(4,5) = 2
dis(4,6) = 4
dis(7,8) = 3
dis(3,6) = 1
	
 
idea-
-get lca of given nodes
-find distance of node1 and node2 res from lca
-sum of above dists reqd ans

*/


// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int findDist(Node *, int, int);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        cout << findDist(root, n1, n2) << "\n";
    }
    return 0;
}// } Driver Code Ends

