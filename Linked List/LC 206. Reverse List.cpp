/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
