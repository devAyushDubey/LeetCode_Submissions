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
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL)
            return head;
        
        ListNode* ptr = head;
        
        while(ptr->next!=NULL){
            if(ptr >= ptr->next)
                break;
            
            ptr = ptr->next;
        }
        
        return ptr->next;
    }
};