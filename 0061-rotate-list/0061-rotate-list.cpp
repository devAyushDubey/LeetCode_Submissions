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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* ptr = head;
        
        if(head==NULL)
            return head;
        
        vector<int> vec;
        while(ptr!=NULL){
            vec.push_back(ptr->val);
            ptr = ptr -> next;
        }
        ptr = head;
        int cnt = vec.size();
        
        if(k==cnt)
            return head;
        
        int rot = k%cnt;
        
        
        int i = 0;
        vector<int> rotated;
        
        while(i<rot){
            rotated.push_back(vec[vec.size()-1]);
            vec.pop_back();
            i++;
        }
        
        reverse(rotated.begin(),rotated.end());
        
        for(auto it: rotated){
            //cout<<it<<" ";
            ptr ->val = it;
            ptr = ptr->next;
        }
        for(auto it: vec){
            //cout<<it<<" ";
            ptr -> val = it;
            ptr = ptr -> next;
        }
            
        return head;
        
    }
};