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
