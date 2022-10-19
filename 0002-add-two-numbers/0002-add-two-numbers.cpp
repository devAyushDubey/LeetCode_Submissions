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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        
        int len1 = 0;
        while(ptr1!=NULL){
            ptr1 = ptr1->next;
            len1++;
        }
        int len2 = 0;
        while(ptr2!=NULL){
            ptr2 = ptr2->next;
            len2++;
        }
        ListNode* start;
        if(len1>len2)
            start = l1;
        else
            start = l2;
        
        ptr1=l1;
        ptr2=l2;
        ListNode* ptr3=start;
        ListNode* p_ptr;
        int carry = 0;
        while(ptr1!=NULL && ptr2!=NULL){
            p_ptr = ptr3;
            int sum = carry + (ptr1->val + ptr2->val);
            carry = sum/10;
            cout<<sum<<" ";
            ptr3->val = sum%10;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            ptr3 = ptr3 -> next;
            
        }
        cout<<endl;
        while(ptr3!=NULL){
            if(ptr1==NULL){
                while(ptr2!=NULL){
                    p_ptr = ptr3;
                    int sum = carry + (ptr2->val);
                    ptr3-> val = sum%10;
                    carry = sum/10;
                    ptr2 = ptr2->next;
                    cout<<sum<<" ";
                    ptr3 = ptr3->next;
                }
            }
            else{
                while(ptr1!=NULL){
                    p_ptr = ptr3;
                    int sum = carry + (ptr1->val);
                    ptr3-> val = sum%10;
                    carry = sum/10;
                    ptr1 = ptr1->next;
                    cout<<sum<<" ";
                    ptr3 = ptr3->next;
                }
            }
            
        }
        
        
        while(carry){
            if(ptr3==NULL){
                ptr3 = p_ptr;
            }
            ListNode *temp = new ListNode();
            temp->val = carry%10;
            temp->next = NULL;
            carry = carry/10;
            ptr3->next = temp;
            ptr3 = ptr3->next;
        }
        
        
        return start;
    }
};