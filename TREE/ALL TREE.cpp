
//2. CLONE A BT WITH RANDOM NEXT 
// T & S:O(n), using map -->??discuss S:O(1) soln 

void linkLRR(Node* t, map<Node*, Node*>&mp)
{
    if(t == NULL)
        return;
    
    if(t->left != NULL)    
        mp[t]->left = mp[t->left];
    if(t->right != NULL)
        mp[t]->right = mp[t->right];
    if(t->random != NULL)
        mp[t]->random = mp[t->random];
    
    linkLRR(t->left, mp);
    linkLRR(t->right, mp);
}
void mapTree(Node* t, map<Node*,Node*>&mp)
{
    if(t == NULL)
        return;
    
    Node* hc = new Node(t->data);
    mp[t] = hc;
    
    mapTree(t->left, mp);
    mapTree(t->right, mp);
}
Node* cloneTree(Node* tree)
{
    if(tree == NULL)
        return NULL;
    
    map<Node*, Node*> mp;
    Node* t = tree;
    
    mapTree(t, mp);
    
    linkLRR(t,mp);
    
    Node* hc = mp[tree];
    return hc;    
}



//17.POPULATE NEXT RIGHT POINTER
// https://www.geeksforgeeks.org/connect-nodes-at-same-level-with-o1-extra-space/

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


//FOR COMPLETE BST (Aabove apprch may give tle)
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
    // connectNext(root);

*************************************************
//3.BT TRAVERSALs : ITERATIVE--> T: O(n), S: O(n)

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


//8. RECOVER BST IF TWO NODES ARE SWAPPED INITIALLY
// https://www.geeksforgeeks.org/fix-two-swapped-nodes-of-bst/

/*  T:O(n) (Single Pass)
    idea- inorder of bst => sorted
    The inorder of given bst there can be either two or one point where sort will be violated
    -two points where curr is less than prev => two non adjacent nodes swapped --> making first point to the prev node and last will then point to next node which for which we'll encounter curr < prev
    -only one such point => two adjacent nodes are swapped-->first will point to prev and middle will point to curr and these two will be the required nodes (in this case last will remain NULLs)

*/
void inorderTraversal(TreeNode* root, TreeNode **first, TreeNode **mid, TreeNode **last, TreeNode  **prev) //**-> for keeping address of the pointer type var (as these are already pointers)
    {
        if(root == NULL) return;
        
        inorderTraversal(root->left, first, mid, last, prev);
       
        if( *prev and root->val < (*prev)->val)
        {
           if(! *first)
           {
               *first = *prev;
               *mid = root;
           }
            else
                *last = root; 
        }
        *prev = root;
        
        if(*first and *last) return;
        
        inorderTraversal(root->right, first, mid, last, prev);
        
    }
    void recoverTree(TreeNode* root) {

        if(root == NULL or (root->left == NULL and root->right == NULL)) return;
        
        TreeNode *prev, *first, *mid, *last;
        prev = first = mid = last = NULL;
        
        inorderTraversal(root, &first, &mid, &last, &prev); //passing addr of pointer so as the changes made by the func must be reflected in the original pointers as well
        
        if(first and last)
            swap(first->val, last->val);
        else if(first and mid)
            swap(first->val, mid->val);
    }




//33. MORRIS TRAVERSAL : T:O(N), S:O(1)
// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/

vector<int> inorderTraversal(TreeNode* root) {
     
        vector<int> res;
        TreeNode* curr = root;
        
        while(curr != NULL){
            
            if(curr->left == NULL){
                res.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* pre = curr->left;
                
                while(pre->right != NULL and pre->right != curr)
                {
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = curr;
                    curr = curr->left;
                }
                else{   //when pre->right == curr; ie left is already traversed so now again changing the links of tree nodes to origin node after storing the curr node 
                    pre->right = NULL;
                    
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }   
        return res;
    }
/* 
-link inorder predecessor of curr to the curr node;
- Initialize current as root 
While current is not NULL
   If the current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Make current as the right child of the rightmost 
         node in current's left subtree
      b) Go to this left child, i.e., current = current->left
*/




//27. CHECK IF GIVEN ARRAY CAN REPRESENT PRE-ORDER TRAVERSAL OF BT OR NOT
//https://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/
//approach - next greater element(using stack)



//30. FIND POSTORDER FROM PREORDER TRAVERSAL
// https://www.geeksforgeeks.org/find-postorder-traversal-of-bst-from-preorder-traversal/


//35. INORDER SUCCESSOR
//https://www.geeksforgeeks.org/find-postorder-traversal-of-bst-from-preorder-traversal/






*************************************************************************

//4. Views

//Diagonal Traversal
void diagonalPrint(Node* root, int d, map<int, vector<int> > diagonalPrint)
{
     if(!root) return;
     
     diagonalPrint[d].push_back(root->data);
     
     diagonalPrint(root->right, d, diagonalPrint);
     diagonalPrint(root->left, d+1, diagonalPrint);
	
}
void diagonalPrint(Node* root) 
{ 
    // create a map of vectors to store Diagonal elements 
    map<int, vector<int> > diagonalPrint; 
    
    diagonalPrint(root, 0, diagonalPrint); 
  
    cout << "Diagonal Traversal of binary tree : n"; 
    for (auto it = diagonalPrint.begin(); 
         it != diagonalPrint.end(); ++it) 
    { 
        for (auto itr = it->second.begin(); 
             itr != it->second.end(); ++itr) 
            cout << *itr  << ' '; 
  
        cout << 'n'; 
    } 
}

/*
idea-
-d-> diagonal distance
-map<->diagonalPrint-> store all the elements at same diagonal distance in a vector(ie with d as key)
-diagonal distance of right child of a node is same as its parent and that of left child is +1 (therefore d+1 in recursive call) of its parent
*/


//LEFT VIEW 
//??discuss recursive sol
void leftView(Node *root)
{
    if(root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        int lsize = q.size();
        
        cout<<q.front()->data<<" ";
        while(lsize--)
        {
            Node* curr = q.front();
            q.pop();
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
}

//RIGHT VIEW - same as above except print last node of level instead of first;

//BOTTOM VIEW -s
// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

void findBV(Node* root, int hd, map<int, pair<Node*,int>> &mp, int depth)
{
    if(root == NULL)
        return;
    
    if(mp.find(hd) != mp.end())
    {
        if(depth >= mp[hd].second) //(>)to ensure if same hd appears then depth most will be visible,(=)to ensure if same depth then the node which comes right most(ie node which comes later will be visible)
            mp[hd] = {root, depth};
    }
    else{
        mp[hd] = {root, depth};
    }
    
    findBV(root->left, hd-1, mp,depth+1);
    findBV(root->right, hd+1, mp,depth+1);
}
vector <int> bottomView(Node *root)
{
    map<int, pair<Node*,int>> mp; //{hd,{root, depth}}
    vector<int> res;
    
    findBV(root, 0, mp,0);
    
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        res.push_back((it->second).first->data);
    }
    
    return res;
}


//VERTICAL VIEW - ??WA
void traverse(Node* root, int hd, map<int, vector<int>> &mp)
{
    if(root == NULL)
        return;
    mp[hd].push_back(root->data); //for top view only one element will be reqd for each hd  
    
    traverse(root->left, hd-1, mp);
    traverse(root->right, hd+1, mp);
}
vector<int> verticalOrder(Node *root)
{
    if(root == NULL)
        return {};
    
    map<int, vector<int>> mp;

    traverse(root, 0, mp);
    
    vector<int>res;
    
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        for(auto a : it->second)
        {
            res.push_back(a);
        }
    }
    return res;
}

//BOUNDARY TRAVERSAL 
//https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
//printLeftBoundary(top-down)->printLeaves(left to right)->printRightBoundary(bottom-up)

vector<int>res;
void leftBoundary(Node* root)
{
    if(root == NULL) return;
    if(root->left) //ie to esure we dont add leaf node(ie root->data is being added only when it has either left or right child.(so as to avoid repition of leaf nodes when pritLeaves() fun will be called))
    {
        res.push_back(root->data); //storing root before calling again as to maintain top-down order
        leftBoundary(root->left);
    }
    else if(root->right) //if no left subtree
    {
        res.push_back(root->data);
        leftBoundary(root->right);
    }
}
void printLeaves(Node* root)
{
    if(root==NULL)
        return;
    printLeaves(root->left); //to print leaves from left to right
    
    if(root->left == NULL && root->right == NULL)
        res.push_back(root->data);
    
    printLeaves(root->right);
}

void rightBoundary(Node* root)
{
    if(root==NULL)  return;
    
    if(root->right)
    {
        rightBoundary(root->right);//calling again before storing root as to maintain bottom-up order
        res.push_back(root->data);
    }
    else if(root->left) //if no right subtree => if left child is present it'll be visible in right boundary
    {
        rightBoundary(root->left);
        res.push_back(root->data);
    }
}

vector <int> printBoundary(Node *root)
{
    res.clear();   
    if(root==NULL)  return res;
    
    res.push_back(root->data);
    leftBoundary(root->left);//top->down
    printLeaves(root);
    rightBoundary(root->right);//bottom->up
    
    return res;
}




************************************************************

//5. DIAMETER OF BT
// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
// T: O(N)
int height(Node* root, int &ans)
{
    if(root == NULL)
        return 0;
    
    int lh = height(root->left, ans);
    int rh = height(root->right, ans);

    ans = max(ans, 1+lh+rh);    //1+lh+rh=>diameter

    return 1+max(lh, rh);  //returning height of root
    
}
int diameter(Node* node) {
    if(node == NULL)
        return 0;
    
    int ans = INT_MIN;
    height(node,ans);

    return ans;
}
// M2->
//TLE may occur. suggested to do with above approach
map<Node*, int> mp;
int height(Node* &root, map<Node*, int>& mp)
{
    if(root == NULL)
        return 0;
    if(mp.find(root) != mp.end())
        return mp[root];
        
    mp[root] = 1 + max(height(root->left,mp), height(root->right,mp));

    return mp[root];
}
int diameter(Node* node) {
    if(node == NULL)
        return 0;
    
    
    int lh = height(node->left, mp);
    int rh = height(node->right, mp);

    return max(1+lh+rh, max(diameter(node->left), diameter(node->right)));
}

******************************************************
//6. FLATTEN BT (bt to Singly LL) :O(n)
// https://www.geeksforgeeks.org/flatten-a-binary-tree-into-linked-list/
void flatten(TreeNode* root) {
        
        if(root == NULL or (root->left == NULL and root->right == NULL))
            return;
        
        if(root->left)
        {
            flatten(root->left);
            
            TreeNode *rightSubTree = root->right;   //*
            
            root->right = root->left;
            root->left = NULL;
            
            TreeNode* tright = root->right;
            while(tright->right)
                tright = tright->right;
            
            tright->right = rightSubTree;                
            
        }
        flatten(root->right);   
    }


// BT to DLL (dll should represent inorder of bts)
// https://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-2/?ref=rp

// traverse inorder, 
// keep track of prev node
// curr->left = prev
// prev->right = curr

void BtToDll(Node* root, Node* &head, Node* &prev)
{
    if(root == NULL) return;
    
    BtToDll(root->left, head, prev);
    
    if(prev == NULL)
        head = root;
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root; 
    BtToDll(root->right, head, prev);   
}

Node * bToDLL(Node *root)
{
    if(root == NULL or (root->left == NULL and root->right == NULL))
        return root;    
    
    Node* head = NULL;
    Node* prev = NULL;
    
    BtToDll(root, head, prev);

    return head; 
}



****************************************************************
// 7.CONVERT INTO MIRROR TREE
void mirror(Node* node) 
{
    if(node == NULL) return;
    
    mirror(node->left);
    mirror(node->right);
    
    Node* temp = node->left;
    node->left = node->right;
    node->right = temp;   
}

//9. Is IDENTICAL {identical => exactly same tree}
//https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
bool isIdentical(Node *r1, Node *r2)
{
    if(r1 == NULL and r2 == NULL) return true;
    
    if((r1 == NULL or r2 == NULL))
        return false;
    
    return (r1->data == r2->data) and
    isIdentical(r1->left, r2->left) and
    isIdentical(r1->right, r2->right);
    
}

//* Transform to Sum Tree (node=(node->lefttree+righttree), leafnode=0)
//https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1
//ip-           10                          
//           /      \                   
//         -2        6                  
//        /   \     /  \                    
//      8     -4   7    5                       
// op-         20
//           /    \
//         4        12
//        /  \     /  \
//      0     0   0    0

int sumTree(Node* node)
{
    if(node==NULL)
        return 0;
    int prev = node->data;
    
    node->data = sumTree(node->left)+sumTree(node->right);
    
    return prev + node->data; 
}

void toSumTree(Node *node)
{
    if(node==NULL)
        return;
    
    sumTree(node);
}




//10. Is Symmetric (check if  tree is mirror image of itself)
// O(n)
bool isMirror(Node* root1, Node* root2)
{
    if(root1 == NULL and root2 == NULL)
        return true;
    
    if(root1 == NULL or root2 == NULL)
        return false;
    
    return (root1->data == root2->data) &&
        isMirror(root1->left, root2->right) &&
        isMirror(root1->right, root2->left);
}
bool isSymmetric(Node* root)
{
    if(root == NULL or (!root->left and !root->right))
        return true;
        
    return isMirror(root, root);
}



//11. ISOMORPHIC :O(min(m,n))

// Two trees isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes.
// https://www.geeksforgeeks.org/tree-isomorphism-problem/
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


//12. VALIDATE BST (isBST)
    bool isBst(TreeNode* root, long left, long right)
    {
        if(root == NULL)
            return true;
        
        if((root->val <= left) or (root->val >= right))
            return false;
            
        return isBst(root->left, left, root->val) and
               isBst(root->right, root->val, right);
    }
    bool isValidBST(TreeNode* root) {
        if(root ==  NULL or (root->left == NULL and root->right == NULL))
            return true;
        
        return isBst(root, LONG_MIN, LONG_MAX);
        
    }


//18. HEIGHT BALANCED BT (isBALANCED)

    bool isBalanced(TreeNode* root, int &height)
    {
        if(root == NULL)
            return true;
        
        int lh = 0, rh = 0; //ht of left and right subtrees resp
        
        int leftBalance = isBalanced(root->left, lh);
        int rightBalance = isBalanced(root->right, rh);
        
        //ht of curr node
        height = max(lh, rh) + 1;
        
        if(abs(lh - rh) >= 2)
            return false;
        
        return leftBalance && rightBalance;
        
    }
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL or (root->left == NULL and root->right == NULL)) 
            return true;
        
        int height = 0;
        
        return isBalanced(root, height);
    }


//19. MIN DISTANCE BETWEEN TWO NODES IN A BT
// https://www.geeksforgeeks.org/find-distance-between-two-nodes-of-a-binary-tree/
Node* Lca(Node* root, int a, int b)
{
    if(root == NULL) return NULL;
    
    if(root->data == a or root->data == b)
        return root;
    
    Node* l = Lca(root->left, a, b);
    Node* r = Lca(root->right, a, b);
    
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
    
    Node* lca = Lca(root, a, b);
    
    int lcaToADis = 0;
    distFromLca(lca, a, lcaToADis);
    int lcaToBDis = 0;
    distFromLca(lca, b,lcaToBDis);
    
    return lcaToADis + lcaToBDis;
}



******************************************************

//15.BT Construction using INORDER and PREORDER traversal

    
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

//BT Construction using INORDER and POSTORDER traversal

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inS, int inE, int &       postInd, map<int, int>& inorder_map){
        
        if(inS>inE)
            return NULL;
        
        TreeNode* tnode = new TreeNode(postorder[postInd--]);
        
        if(inS==inE)
            return tnode;
        
        int searchInd = inorder_map[tnode->val]; //index of tnode->val in inorder traversal
        
        tnode->right =  buildTree(inorder, postorder, searchInd+1, inE, postInd, inorder_map);
        tnode->left =  buildTree(inorder, postorder, inS, searchInd-1, postInd, inorder_map);
        
        return tnode;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len=inorder.size();
        if(len==0)
           return NULL;
        
        int postInd=len-1;
        map<int, int>inorder_map;
        for(int i=0;i<len;i++)
            inorder_map[inorder[i]]=i;
        
        return buildTree(inorder, postorder, 0, len-1, postInd, inorder_map);
    }

// Construction of BT using INORDERE & LEVEL ORDER TRAVERSAL
// https://www.geeksforgeeks.org/construct-tree-inorder-level-order-traversals/



//Construct BST from given PREORDER - {T&S: O(n)} :(n in building tree and n for nextgreater)
// https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/

    map<int, int> ngInd;   
    void nextGreater(vector<int> arr)
    {
        stack<int> st;
        int i =0, n = arr.size()-1;
        
        while(i <= n)
        {
            if(st.empty() || arr[st.top()] > arr[i])
                st.push(i++);
            else{
                while(!st.empty() && arr[st.top()] < arr[i])
                {
                    ngInd[st.top()] = i;
                    st.pop();
                }
            }
        }
        while(!st.empty())
        {
            //n+1 so even if all elements are in descend order then this will ensure to make skew tree( by placing the elements lets say in left subtree only)
            ngInd[st.top()] = n+1; 
            st.pop();
        }
    }
    
    TreeNode* buildTree(vector<int> &preorder,int l, int h)
    {
        if(l > h)
            return NULL;
        
        int nextInd = ngInd[l]; // first is root in preorder traversal
        TreeNode* root = new TreeNode(preorder[l]);
        
        if(l == h)
            return root;
        
        //if nextInd == n+1 => if(no next greater then left subtree will contain all the elements from l+1 to the end of the array)
        root->left = buildTree(preorder, l+1, nextInd - 1);  
        root->right = buildTree(preorder, nextInd, h);
        
        return root;   
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n = preorder.size();
        
        //this is to map every index with their next greater index
        nextGreater(preorder);
        for(auto it = ngInd.begin(); it != ngInd.end(); it++)
                cout<<it->first<<" "<<it->second<<endl;
        
        return buildTree(preorder, 0, n-1);
            
    }



//FIND POSTORDER TRAVERSAL OF TREE FROM GIVEN PREORDERS
// https://www.geeksforgeeks.org/find-postorder-traversal-of-bst-from-preorder-traversal/
// M1-> construct bst from preorder as done above then find postorder traversal
// M2-> without constructing tree-> setting range and finding
//postorder- L->R->root : order of execution
vector<int>postorder;
void findPostOrder(vector<int> pre, int& preInd, int l, int h)
{
    
    if(pre[preInd] >= h or pre[preInd] <= l) //ie if not in range
        return;
    
    int val = pre[preInd++];
    
    //left subtree
    findPostOrder(pre, preInd, l, val);
    //right subtree
    findPostOrder(pre, preInd, val, h);
    
    postorder.push_back(val); 
}
// findPostOrder(pre, preInd, INT_MIN, INT_MAX); //preInd = 0: during first func call


***********************************************************
//23. ALL NODES AT A DISTANCE K FROM TARGET NODE
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/solution/

void mapParent(TreeNode *root, map<TreeNode*, TreeNode*> &mp)
    {
        if(root == NULL) return;
        if(root->left){
            if(mp.find(root->left) == mp.end())
            mp[root->left] =root;
        }
        if(root->right)
        { 
            if(mp.find( root->right) == mp.end())
                mp[root->right] =root;

        }
        mapParent(root->left, mp);
        mapParent(root->right, mp);
        
    }  
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
     
        if(K == 0) return {target->val};
        vector<int> res;
        
        map<TreeNode*, TreeNode*> mp;
        mp[root] =NULL;
        
        mapParent(root,mp);
        
        queue<TreeNode*> q;
        if(mp[target])q.push(mp[target]);
        if(target->left)q.push(target->left);
        if(target->right)q.push(target->right);
        K--;
        
        set<TreeNode*> visited;
        visited.insert(target);
        visited.insert(mp[target]);
        if(target->left)visited.insert(target->left);
        if(target->right)visited.insert(target->right);
        
        
        while(!q.empty())
        {
            int levelSize = q.size();
            
            if(K)
                while(levelSize--)
                {
                    TreeNode* curr = q.front();
                    q.pop();
                    
                    if(mp[curr] and visited.find(mp[curr]) == visited.end())
                    {
                        q.push(mp[curr]);
                        visited.insert(mp[curr]);    
                    }
                    if(curr->left and visited.find(curr->left) == visited.end())
                    {
                        q.push(curr->left);
                        visited.insert(curr->left);    
                    }
                    if(curr->right and visited.find(curr->right) == visited.end())
                    {
                        q.push(curr->right);
                        visited.insert(curr->right);    
                    }                   
                    
                } 
            if(K)K--;
            
            if(K == 0 )
                while(!q.empty())
                {
                    if(q.front())res.push_back(q.front()->val);
                    q.pop();
                }
        }
        
        return res;
    }

// 31. Kth ANCESTOR OF A NODE IN BT

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
    Node* node1;   
    map<Node*, Node*> :: iterator it = parent.begin();
    
    while(it != parent.end()) //reaching "node" in given tree
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



//25. REMOVE HALF NODES
// https://practice.geeksforgeeks.org/problems/remove-half-nodes/1
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


//28.find Height of BT represented by parent array;
//https://www.geeksforgeeks.org/find-height-binary-tree-represented-parent-array/
void findDepth(int parent[], int i, int depth[])
{
	if(depth[i])
		return;
	if(parent[i] == -1)
	{
		depth[i] = 1;	//depth of root node = 1
		return;
	}
	if(depth[parent[i]] == 0)
		findDepth(parent, parent[i],  depth);
		
	depth[i] = 1 + depth[parent[i]];
	
}
int findHeight(int parent[], int n)
{
	int depth[n];
	memset(depth, 0, sizeof(depth));

	for(int i = 0; i < n; i++)
		findDepth(parent, i, depth);
	
	return *max_element(depth + 0, depth + n);
}
// findHeight(parent, n);  : parent[n]

/* T: O(n)
ip-parent[] = {-1, 0, 0, 1, 1, 3, 5};
op- 5 (no of nodes from root to deepest leaf)

	 0
       /   \
      1     2
     / \
    3   4
   /
  5 
 /
6
*/


*************************************************

//14.Path sum equals given sum (root->leaf path)
// https://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/s
bool hasPath(Node* root, int sum)
{
    if(root == NULL and sum == 0)
        return true;
    if(root == NULL or sum == 0)
        return false;
    
    return hasPath(root->left, sum - root->data) || 
    hasPath(root->right, sum - root->data);
}

bool hasPathSum(Node *node, int sum) {
    
    
    if(node == NULL)
        return false;
        
    return hasPath(node->left, sum-node->data)
        or hasPath(node->right, sum- node->data);
    
    
}


//24. Maximum sum of nodes in Binary tree such that no two are adjacent :O(n)
// https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/
pair<int, int> maxSum(Node* root)
{
	if(root == NULL) 
		return {0,0};
		
	pair<int, int> l = maxSum(root->left);
	pair<int, int> r = maxSum(root->right);
	
	pair<int, int> curr = make_pair(0,0);
	//taken, notTaken resp
	curr.first = root->data + l.second + r.second;
	curr.second = max(l.first, l.second) + max(r.first, r.second);
	
	return curr;
}
int maxSumFun(Node* root)
{
	//pair-> rootTaken, rootNotTaken
	pair<int, int> res = maxSum(root);
	return max(res.first, res.second);
}




//LC: ROOT TO LEAF SUM (ROOT TO LEAF PATH APPROACH)

int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        
        stack<TreeNode*>st;
        map<TreeNode*,  TreeNode*> parent;        
        int totalPathSum=0;
        
        st.push(root);
        parent[root]=NULL;
        
        while(!st.empty()){
            TreeNode* curr=st.top();
            st.pop();
            
            //curr is leaf node=>traverse for path from                                                 curr to root through parent 
            if(!curr->left and !curr->right) 
            {
                string onePathSum="";
                TreeNode* temp= curr;
                while(temp){
                    onePathSum= to_string(temp->val) + onePathSum;
                    temp=parent[temp];
                }
                
                totalPathSum+=stoi(onePathSum);
            }
            
            //right first in stack(so it'll be processed later) as we want                                  to process left before right
            if(curr->right) 
            {
                st.push(curr->right);
                parent[curr->right]=curr;
            }
            
            if(curr->left) 
            {
                st.push(curr->left);
                parent[curr->left]=curr;
            }
                
        }
        
        return totalPathSum;
    }


//MAXIMUM PATH SUM BETWEEN 2 LEAF NODES!!
// https://practice.geeksforgeeks.org/problems/maximum-path-sum/1/
//code is similar to that of DIAMETER of BT
int maxSum(Node* root, int& sum)
{
    if(root == NULL) 
        return INT_MIN;
        
    if(root->left == NULL && root->right == NULL) //root is leaf node
        return root->data;
       
    int l = maxSum(root->left, sum); 
    int r = maxSum(root->right, sum);
    
    if(root->left && root->right) 
        sum = max(sum, l+r+root->data);
    
    return max(l,r)+root->data;
}

int maxPathSum(Node* root)
{ 
    if(root == NULL)
        return 0;
    
    int sum = INT_MIN;
    maxSum(root, sum);
    return sum;
}
ip-        3                              
         /    \                          
       4       5                     
      /  \      
    -10   4       
op- 16

************************************************
//Sorted array to BALANCED BST - T: O(n)
//take mid ele make it root, recursively do it for left and right subarrays
Node* toBST(vector<int>sortedArray, int l, int h)
{
    if(l>h)
        return NULL;

    int mid = (l+h)/2;
    Node* root = new Node(sortedArray[mid]);

    root->left = toBST(sortedArray, l, mid-1);
    root->right = toBST(sortedArray, mid+1, h);

    return root;
}
// toBST(a,0,n-1);

// TO BUILD BALANCED BST FROM NORMAL BST
// get inorder of given bst(which will be sorted), convert it into balanced bst as done above

****************************************************************************************************************

// @paytm:

//Find all duplicate subtrees (duplicate wrt structure of tree)
//https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1
string findDuplicates(Node* root, map<string,int> &mp, vector<int>&res)
{
    if(root == NULL)
        return "";
    
    string str = "(";
    str += findDuplicates(root->left, mp,res);
    str += root->data;
    str += findDuplicates(root->right, mp,res);
    str += ")";
    
    if(mp[str] == 1)
        res.push_back(root->data);
    mp[str]++;
    
    return str;
}
void printAllDups(Node* root)
{
    if(root == NULL) return;
    
    vector<int> res;
    map<string, int> mp;
    findDuplicates(root,mp,res);
    sort(res.begin(), res.end()); //not reqd to sort unless asked in ques
    
    if(res.size() == 0)
        cout<<"-1";
    else{
        for(int a:res)
            cout<<a<<" ";
    }
}
/*
ip-    1
      /  \
     2    3
    / \  / \
   4  3 2   4
       /
      4
op- 4

ip -  1
      / \
     2   3
    /   / \
   4   2   4
      /
     4
op- 2 4
*/


//Rotate Matrix-> by 90 degree ##Do ROTATION METHOD 
// https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/
//anticlockwise -> reverse each row, then find transpose of mat(ie for(i=0;n){for(j=i,n) swap(mat[i][j],mat[j][i])});
//clockwise--> find transpose then swap first column with last column: for(i=0;n)for(j=0;n){a[i][j],a[i][n-j-1]} 


// INVERSION COUNT
//https://practice.geeksforgeeks.org/problems/inversion-of-array/0/


//https://www.geeksforgeeks.org/trapping-rain-water/