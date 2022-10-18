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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL)
            return head;
        
        int cnt = 1;
        ListNode* ptr = head;
        vector<int> even;
        vector<int> odd;
        
        while(ptr!=NULL){
            if(cnt%2==0)
                even.push_back(ptr->val);
            else
                odd.push_back(ptr->val); 

            ptr = ptr->next;
            cnt++;
        }
        
        ptr = head;
        while(ptr!=NULL){
            for(auto it: odd){
                ptr->val = it;
                ptr = ptr->next;
            }
            for(auto it: even){
                ptr->val = it;
                ptr = ptr->next;
            }
        }
        
        return head;
        
    }
};