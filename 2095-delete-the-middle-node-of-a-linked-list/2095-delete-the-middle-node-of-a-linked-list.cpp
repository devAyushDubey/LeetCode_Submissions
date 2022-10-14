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
    ListNode* deleteMiddle(ListNode* head) {
        
        ListNode* ptr = head;
        int n = 0;
        while(ptr != NULL){
            n++;
            ptr = ptr->next;
        }
        
        if(n==1)
            return NULL;
        
        int mid = n/2;
        
        ListNode* temp = head;
        ptr = head;
        for(int i=0;i<mid;i++){
            temp = ptr;
            ptr = ptr->next;
        }
        
        cout<<ptr->val;
        temp->next = ptr->next;
        return head;
    }
};