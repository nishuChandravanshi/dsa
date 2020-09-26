/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
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
};
/*
	//Recursive

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
*/

/*
	T: O(n+m), S:O(1)
idea-
-res is dummy-head whose next will point to the overall merged list
-to maintain sorted list till curr in every iteration 
(via next of curr always pointing to the list with smaller head value, then updating curr to new sorted pos(ie curr=curr->next)
- l1 and l2 will be moved acgly
*/
