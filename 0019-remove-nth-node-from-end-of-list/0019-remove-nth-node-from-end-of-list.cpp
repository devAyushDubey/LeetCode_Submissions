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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL)
            return head;
        
        ListNode* ptr = head;
        int cnt = 0;
        while(ptr!=NULL){
            cnt++;
            ptr=ptr->next;
        }
        
        int l = cnt-n,i=1;
        ptr = head;
        if(l==0)
            head=head->next;
        while(i<=l){
            //cout<<i<<endl;
            if(i==l){
                if(ptr->next->next == NULL)
                    ptr->next = NULL;
                else
                    ptr -> next = ptr -> next -> next;
                break;
            }
            ptr = ptr -> next;
            i++;
        }
        
        return head;
    }
};