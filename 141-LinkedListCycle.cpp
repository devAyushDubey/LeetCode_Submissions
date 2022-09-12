/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
//     struct Node {
//         int pos;
        
//     }
public:
    bool hasCycle(ListNode *head) {
        ListNode* ptr = head;
        ListNode* temp = NULL;
        if(ptr == NULL)
            return false;
        //st.insert(ptr->val);
        while(ptr->next != NULL){
            //cout<<ptr<<endl;
            if(ptr<=temp)
                return true;
            temp = ptr;
            ptr = ptr->next;
        }
        return false;
    }
};