/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

		//Recursive: 1
//https://www.geeksforgeeks.org/connect-nodes-at-same-level-with-o1-extra-space/
class Solution {
public:
    Node* getNext(Node* root)
    {
        Node* temp = root;
        
        temp = temp->next;
        while(temp != NULL)
        {
            if(temp->left)
                return temp->left;
            if(temp->right)
                return temp->right;
            temp = temp->next;
        }
        return NULL;
    }
    
    void connectNext(Node* &root)
    {
        if(!root) return;
        
        if(root->next != NULL)
            connectNext(root->next);
        
        if(root->left)
        {
            if(root->right)
            {
                root->left->next = root->right;
                root->right->next = getNext(root);
            }
            else
                root->left->next = getNext(root);
            
            connectNext(root->left);
        }
        else if(root->right)
        {
            root->right->next = getNext(root);
            
            connectNext(root->right);
        }
        else
        {
            Node* curr = getNext(root);
            connectNext(curr);   
        }
        
    }
    
    Node* connect(Node* root) {
        if(root == NULL) return root;
        
        connectNext(root);
        
        return root;
    }
};

	//Recursive 2:(for complete BT:: -->as above recursive sol may give tle)

//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

class Solution {
public:
    void connectNext(Node* &root)
    {
        if(!root) return;
        
        if(root->left)
        {
            if(root->right)
            {
                root->left->next = root->right;
                if(root->next)
                root->right->next = root->next->left;
            }

        }        
        connectNext(root->left);
        connectNext(root->right);
        
    }
    
    Node* connect(Node* root) {
        if(root == NULL) return root;
        
        connectNext(root);
        
        return root;
    }
};


/*
	T:O(n)
-ip:	    1           
          /    \
        2        3       
       / \      /  \
      4   5    6    7    
     / \           / \
    8   9        10   11 

op:         1 ->null     
          /    \
        2  ->    3       
       / \      /  \
      4 -> 5 -> 6 ->7->null   
     / \           / \
    8 ->9  --->   10->11->null
 
*/




	//Iterative

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int lsize=q.size();
            
            while(lsize){
                Node* curr=q.front();
                q.pop();
                if(lsize==1)
                    curr->next=NULL;
                else{
                    curr->next=q.front();
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                lsize--;     
            }
         
        }
        return root;
    }
};



