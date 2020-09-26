#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int indx,ans;

struct Node{
    int data;
    Node *left,*right;
    
    Node(int d){
        data=d;
        left=right=NULL;
    }
};

int pairsViolatingBST(Node *root,int n);
void insert(Node *root,int a,int b,char ch);

int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
	indx=0;
	ans=0;
        Node *root=NULL;
        for(int j=0;j<n;j++){
            int a,b;
            char ch;
            cin>>a>>b>>ch;
        
	    if(root==NULL){
                root=new Node(a);
                switch(ch){
                    case 'L':root->left=new Node(b);
                            break;
                    case 'R':root->right=new Node(b);
                            break;
                }
            }else{
                insert(root,a,b,ch);
            }
        }
		cout<<pairsViolatingBST(root,n)<<"\n";
    }

	return 0;
}

void insert(Node *root,int a,int b,char ch){
    if(root==NULL)return;
    if(root->data==a){
        switch(ch){
            case 'L':root->left=new Node(b);
                    break;
            case 'R':root->right=new Node(b);
                    break;
        }
    }else{
        insert(root->left,a,b,ch);
        insert(root->right,a,b,ch);
    }
}


/*You are required to complete below method */
void inorderTraversal(Node *root, vector<int> &inorder)
{
    if(root == NULL) return;
    
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

int pairsViolatingBST(Node *root,int n){
    
    vector<int> inorder;
    inorderTraversal(root, inorder);
    
    int count = 0;
    for(int i = 0; i < inorder.size()-1; i++){
        for(int j = i+1; j < inorder.size(); j++){
            if(inorder[i] > inorder[j])
                count++;
        }
    }
    return count;
}

/*
-store inorder traversal 
-count inversion
(=> no of pairs st i<j and a[i]>a[j])
*/
