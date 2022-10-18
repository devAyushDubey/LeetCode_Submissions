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

    ListNode* sortList(ListNode* head) {
        
        ListNode* ptr = head;
        multiset<int> s;
        while(ptr!=NULL){
            s.insert(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        for(auto it: s){
            ptr->val = it;
            ptr = ptr->next;
        }
        
        return head;
    }
};