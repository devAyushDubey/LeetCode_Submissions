/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL)
            return head;
        
        Node* ptr = head;
        Node* head2;
        Node* p_ptr;
        bool first = true;
        unordered_map<Node*,Node*> mp;
        while(ptr!=NULL){
            //cout<<ptr->val<<" ";
            Node *temp = new Node(ptr->val);
            mp[ptr] = temp;
            if(first){
                head2 = temp;
                first = false;
                p_ptr = head2;
                ptr = ptr->next;
                continue;
            }
            p_ptr->next = temp;
            p_ptr = p_ptr->next;
            ptr = ptr->next;   
        }
        for(auto it: mp)
            cout<<it.first<<" "<<it.second<<endl;
        p_ptr = head2;
        ptr = head;
        while(p_ptr!=NULL){
            //cout<<p_ptr->val<<" ";
            if(ptr->random == NULL)
                p_ptr->random = NULL;
            else
                p_ptr->random = mp[ptr->random];
            p_ptr = p_ptr->next;
            ptr = ptr->next;
        }
        
        return head2;
        
    }
};