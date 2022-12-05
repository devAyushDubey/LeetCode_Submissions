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
    ListNode* middleNode(ListNode* head) {
        
        int l = 0;
        ListNode* mid = head;
        ListNode* ptr = head;
        
        while(ptr!=NULL){
            //cout<<mid->val<<" "<<l<<endl;
            if(l%2!=0)
                mid = mid->next;
            l++;
            ptr = ptr->next;
        }
        
        return mid;
    }
};