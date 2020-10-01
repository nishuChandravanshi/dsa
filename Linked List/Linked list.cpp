//1.Reverse LL
class Solution {
public:
    ListNode* recursiveReverse(ListNode* head, ListNode* prev){
        if(head == NULL) return prev;
        
        ListNode* node = head->next;
        head->next = prev;
        return recursiveReverse(node,head);
        
    }

    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL) return NULL;
        
        ListNode* prev = NULL, *next = head->next;
    
        while(next != NULL){
            
            head->next = prev;
            prev = head;
            head = next;
            next = head->next;
            
        }
        
        head->next = prev;
        
        return head;
        
        // return recursiveReverse(head, prev);

    }
};
//2.Intersection of two LL
//https://leetcode.com/problems/intersection-of-two-linked-lists/
class Solution {
public:
    int listSize(ListNode *head)
    {
        if(head == NULL) return 0;
        
        return 1 + listSize(head->next);
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int sizeA = listSize(headA);
        int sizeB = listSize(headB);
        
        ListNode *a = headA;
        ListNode *b = headB;
        
        int shift = abs(sizeA - sizeB);
        
        if(sizeA > sizeB) 
            while(shift--)
                a = a->next;
        else 
            while(shift--)
                b = b->next;
        
        while(a and b and a != b){
            a = a->next;
            b = b->next;
        }
        return a;
        
    }
};


//3. Delete duplicate in sorted list

// delete dupls I
// Input: 1->1->2->3->3
// Output: 1->2->3
 ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        
        ListNode *temp = head;
        ListNode *curr = temp;
        
        while(curr != NULL){
            
            curr = temp;
            while(temp and temp->next and temp->val == temp->next->val)
                temp = temp->next;
            
            curr->next = temp->next;
            if(temp->next == NULL)break;
            if(curr)temp = curr->next;
            
        }
        
        return head;
    }

//5. delete dupls II
// Input: 1->2->3->3->4->4->5
// Output: 1->2->5
// Input: 1->1->1->2->3
// Output: 2->3
ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL or head->next == NULL) return head;
        
        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        
        ListNode *pre = preHead;
        ListNode *curr = head;
        
        while(curr != NULL){
            
            while(curr->next != NULL and curr->val == curr->next->val)
                curr = curr->next;
            if(pre->next == curr) //ie no duplicates
                pre = pre->next;
            else pre->next = curr->next;
            
            curr = curr->next;
        }
        return preHead->next;        
    }


//4. Merge two sorted ll

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      
	if(l1==NULL ) return l2;
        if(l2==NULL) return l1;

	//return merge(l1, l2);        

        ListNode res(0);
        ListNode * curr= &res;
        
        while(l1 and l2)
        {
            if(l1->val < l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
            
        }
        curr->next = l1 ? l1 : l2;

        return res.next;
        
    }

//Recursive
    //S & T: O(m+n)
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode* temp = NULL;
        
        if(l1->val < l2->val)
        {
            temp = l1;
            temp->next = merge(l1->next, l2);
        }
        else 
        {
            temp = l2;
            temp->next = merge(l1, l2->next);
        }
        
        return temp;
    }

/*  iterative-
	T: O(n+m), S:O(1)
idea-
-res is dummy-head whose next will point to the overall merged list
-to maintain sorted list till curr in every iteration 
(via next of curr always pointing to the list with smaller head value, then updating curr to new sorted pos(ie curr=curr->next)
- l1 and l2 will be moved acgly
*/


//Merge k-sorted List : T(O(n*k*k))
// https://leetcode.com/problems/merge-k-sorted-lists/submissions/
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        if(l1->val <= l2->val)
        {
            l1->next = merge(l1->next,l2);
            return l1;
        }
        else{
            l2->next = merge(l1,l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        ListNode* dh = lists[0];
        int i=1;        
        while(i<lists.size())
        {
            dh = merge(dh, lists[i]);
            i++;
        }
        return dh;
    }
};

//using heap-> T:O(n*k*log(k))
class Solution {
public:
    struct cmp{
        bool operator()(ListNode*a, ListNode* b)
        {
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        int k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        for(int i=0;i<k;i++)
            if(lists[i] != NULL)
                pq.push(lists[i]);
        
        ListNode* dh = NULL, *last = NULL;
        while(!pq.empty())
        {
            ListNode* curr  = pq.top();
            pq.pop();
            if(curr->next != NULL)
                pq.push(curr->next);
            if(dh == NULL)
            {
                dh = curr;
                last = dh;
            }
            else{
                last->next = curr;
                last = curr;
            }
        }
        return dh;
    }
    
}; 




//6.Detect loop, //-->do removal
//slow fast => if both ptr(x and 2x speed) start revolving in a circle from a pt then they'll meet again at the starting point.
//https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

ListNode *detectCycle(ListNode *head) {
     
        if(head == NULL or head->next == NULL) return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        if(slow != fast) return NULL;
        
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }


//7.Rotate LinkedList -{if(k>n) rotate at k%n} 
//https://www.geeksforgeeks.org/rotate-a-linked-list/

//Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL
// Input: 0->1->2->NULL, k = 4
// Output: 2->0->1->NULL

ListNode* rotateRight(ListNode* head, int k) {
        
        if(k == 0 or head == NULL or head->next == NULL)
            return head;
        
        ListNode *prev = head;
        ListNode *curr = head;
        
        int listSize = 0;
        while(curr != NULL)
        {
            curr = curr->next;
            listSize++;
        }
        
        curr = head;
        
        if(k%listSize == 0)
            return head;
        else
            k = k%listSize;
        
        
        int count = k;      //forwarding curr by k positions so as to get the point for breaking due to rotation
        while(count-- and curr->next !=NULL)
            curr = curr->next;
        
        
        if(curr->next == NULL and count == 0)
           return head;
        
        
        while(curr->next != NULL){
            prev = prev->next;
            curr = curr->next;
        }
        
        curr->next = head;
        head = prev->next;
        prev->next = NULL;
        
        return head; 
    }

//8. Delete node without head pointer
void deleteNode(*node)
{
    if(node==NULL) return;
    if(node->next == NULL)
        node = NULL;
    else{
        node->val = node->next->val;
        node->next = node->next->next;
    } 
}


//9. Delete Nth node from last of ll

//ip-[1,2] n=2
// op- [2]
// ip- [1,2,3,4,5], n=2
//op- [1,2,3,5]
ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* left  = head;
        ListNode* right = head;
        
        int count = n;
        while(right && count--) //moving right ptr n steps ahead
            right = right->next;
        
        ListNode* prev = NULL;
        while(right != NULL)
        {
            prev = left;
            left = left->next;
            right = right->next;
        }
        
        if(prev != NULL)    //deleting left node
            prev->next = left->next;
        else
            return head->next; //ie deleting nth from end=>deleting first node
        
        return head;
    }

//10. clone ll with random ptr
//https://www.geeksforgeeks.org/clone-linked-list-next-random-pointer-o1-space/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*
                M-1-> T: O(n), Space: O(n)
-In 1st pass only mapping of original nodes is done to newly created nodes( with next and random pointer pointing to NULL)
s 
-In 2nd pass the value side of the map(containing the new nodes) is linked with the help of keys(ie origin list's pointers)

*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* t= head;
        if(t==NULL)
            return NULL;
        
        map<Node*, Node*>mp;
//1st pass        
        while(t){
            Node* h= new Node(t->val);
            
            mp[t]= h;
            
            t=t->next;
        }
        t= head;
        
//2nd pass        
        while(t){
            if(t->random==NULL)
                mp[t]->random=NULL;
            else mp[t]->random= mp[t->random];
            
            if(t->next==NULL)
                mp[t]->next= NULL;
            else mp[t]->next= mp[t->next];
            
            t=t->next;
        }
        
        return mp[head];        
    }



/*
                M-2-> T: O(n), Space: O(1)
-In 1st pass Inserting new nodes in between two nodes by making- originalNode->next=newNode and                                            newNode->next= originalNode->next  
-In 2nd pass new Nodes random pointer is linked by taking reference of prev original nodes

*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* original= head;
        if(original==NULL)
            return NULL;
        
// 1st pass 
        while(original){
            Node* temp= original->next;
            
            original->next= new Node(original->val);
            original->next->next= temp; //ie newNext= temp
            
            original= temp;
        }
//2nd pass        
        original= head;
        while(original){
            
            if(original->next)
                original->next->random= original->random? original->random->next: original->random;
            
            original= original->next? original->next->next: original->next;
            
        }
        original=head;
        
//separating original and new LL
        Node* head2= original->next;
        Node* clone = head2;
        while(original and clone){
            if(original->next)
            {
                original->next= original->next->next;
                original= original->next;
            }
            
            if(clone->next){
                clone->next= clone->next->next;
                clone= clone->next;
            }
            
        }
        return head2;
        
    }
};


//11. merge sort in ll

// Input: 4->2->1->3
// Output: 1->2->3->4
void divideList(Node* head, Node* &a, Node* &b)
{
    if(head == NULL)
        return;
    Node* slow = head;
    Node* fast = head;
    
    Node* prev = NULL;
    while(fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    a = head;
    b = slow;
    prev->next = NULL; //cut connection
}

Node* mergeSorted(Node* a, Node* b)
{
    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;
    
    Node* res = NULL;
    if(a->data < b->data)
    {
        res = a;
        res->next = mergeSorted(a->next,b);
    }
    else{
        res = b;
        res->next = mergeSorted(a, b->next);
    }
    
    return res;
}


Node* mergeSort(Node* head) {
    if(head == NULL or head->next == NULL)
        return head;
    
    Node* a = NULL;
    Node* b = NULL;
    
    divideList(head, a, b);
    
    Node* c = mergeSort(a);
    Node* d = mergeSort(b);
    
    return mergeSorted(c, d);
}


//17.Quick sort LL

//target -> to place pivot in its right place!
//idea-> to take last elem as pivot, start from beginniing of list->add the node greater than pivot at the end of the list

class Solution {    //LC: TLE!
public:
    ListNode* getTail(ListNode* node)
    {
        if(node == NULL or node->next == NULL)
            return node;
        
        while(node != NULL && node->next != NULL)
            node = node->next;
        
        return node;        
    }
    
    ListNode* partition(ListNode* head, ListNode* tail, ListNode* &newHead, ListNode* &newTail, ListNode* &prevPiv)
    {
        if(head == NULL or head == tail)
            return head;
        
        ListNode* curr = head;
        ListNode* pivot = tail;
        
        
        while(curr!= NULL && curr != pivot)
        {
            if(curr->val < pivot->val)
            {
                if(newHead == NULL)
                    newHead = curr;
                
                prevPiv = curr; //as curr can be the prev of piv in this case
                curr = curr->next;
            }
            else
            {
                //ie theres list in left of curr which contains elements smaller than pivot
                if(prevPiv)
                {
                    prevPiv->next = pivot;
                }
                ListNode* temp = curr->next;
                curr->next = NULL;        
                tail->next = curr;
                tail = curr;
                curr = temp;
            }
        }
        if(newHead == NULL)
            newHead = pivot;
        
        newTail = tail;
        
        return pivot;
        
    }
    
    ListNode* quickSort(ListNode* head, ListNode* tail)
    {
        if(head == NULL or head == tail)
            return head;
        
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;
        ListNode* prevPiv = NULL;
        
        //partition will return pivot after placing it in its correct position
        ListNode* pivot = partition(head, tail, newHead, newTail, prevPiv);
        
        //if pivot==newHead=> pivot is smallest : no need to recur for left of list
        if(pivot != newHead) 
        {
            if(prevPiv)
                prevPiv->next = NULL; //breaking connection of list on left of pivot
            
            newHead = quickSort(newHead, prevPiv); 
            
            if(getTail(newHead) != NULL)
                getTail(newHead)->next = pivot; //connecting left sorted list to pivot
        }
        
        pivot->next = quickSort(pivot->next, newTail);
        
        return newHead;       
        
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL or head->next == NULL)
            return head;
        
        ListNode* tail = getTail(head);
    
        return quickSort(head, tail);
    }
};



//12. flatten a LL {recursive merge}
/*ip-  5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
op- 5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50
*/
Node *merge (Node *h1,Node *h2)
{
    if(h1==NULL) return(h2);
    if(h2==NULL) return(h1);
    
    if(h1->data < h2->data) {
        h1->bottom = merge(h1->bottom, h2);
        return(h1);
    }
    else{
        h2->bottom = merge(h1, h2->bottom);
        return(h2);
        
    }
}
Node *flatten(Node *root)
{
    Node *a =root;
    Node *b=root->next;
    while(b!=NULL)
    {
        Node *c=b->next;
        a=merge(a,b);
        b=c;
        
    }
    return(a);
}


//13. Add two lists represented as numbers

//https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode *res = l1;
        int carry = 0;
        int sum =0;
        
        while(1)
        {
            sum = l1->val + l2->val + carry;
            
            if(sum < 10){
                l1->val = sum;
                carry = 0;
            }
            else{
                l1->val = sum%10;
                carry = 1;
            }    
           
            if(l1->next and l2->next){
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1->next == NULL and l2->next == NULL ){
            
                if(!carry) break;
                else l1->next = new ListNode(carry);
                
                break;
            } 
            
            else if(l1->next == NULL){
                
                ListNode* temp = l2->next;
                while(carry and l2->next != NULL){
                    sum = l2->next->val + carry;
                    
                    l2->next->val = sum%10;
                    
                    sum > 9 ? (carry = 1) : (carry = 0);
                    
                    l2 = l2->next;
               }
                l1->next = temp;
                
                if(l2->next == NULL and carry )
                    l2->next = new ListNode(carry);
            
                break;
            }
            
            else if(l2->next == NULL)
            {
                while(carry and l1->next){
                    sum =  l1->next->val + carry;         
                    
                    l1->next->val = sum%10;
                    
                    sum > 9 ? (carry = 1) : (carry = 0);
                    
                    l1 = l1->next;
                }
                if(carry)
                    l1->next = new ListNode(carry);
                break;          
                
            }         
            
            
        }
        return res;
    }

//14. Palindrome linked list

// Input: 1->2->1
// Output: true
// Input: 1->3->3->1
// Output: true

ListNode* reverse(ListNode* head){
        if(head == NULL or head->next == NULL) return head;
        
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *curr_next = curr->next;
           
        while(curr_next != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = curr_next;
            curr_next = curr_next->next;
        }
        curr->next = prev;
        
        return curr;
        
    }
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL or head->next == NULL ) return true;
        
        ListNode *slow = head, *prev_slow = NULL;
        ListNode *fast = head;
        ListNode *mid;
        
        while(fast and fast->next){
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *head2;
        
        if(fast != NULL){   //=>odd length
            mid = slow;
            prev_slow->next = slow->next;
            
            head2 = slow->next;
        }
        else{
            prev_slow->next = NULL;
            head2 = slow;
        }
        
        head2 = reverse(head2);
        
        while(head and head2){
        
            if(head->val != head2->val)
                return false;
            
            head = head->next;
            head2 = head2->next;
        }

        return true;
    }


//15. Rearrange in zigzag order
//16. Rearrange in alternate first and last node




**************************************************************************************************************************************************************************************

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
