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
        unordered_map<ListNode*,int> mp;
        
        mp[ptr]++;
        ptr = ptr -> next;
        
        while(ptr!=NULL){
            
            if(mp[ptr])
                break;
            
            mp[ptr]++;
            ptr = ptr->next;
        }
        
        
        return ptr;
    }
};