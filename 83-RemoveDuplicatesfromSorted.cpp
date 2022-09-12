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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_set<int> st;
        ListNode* ptr = head;
        ListNode * prev_ptr = NULL;
        while(ptr != NULL){
            if(st.find(ptr->val) == st.end()){
                st.insert(ptr->val);
                prev_ptr = ptr;
            }
            else{
                prev_ptr->next = ptr->next;
            }
            
            ptr = ptr->next;
                
        }
        return head;
    }
};