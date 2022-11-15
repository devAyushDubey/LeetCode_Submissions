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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void forevery(ListNode* head, TreeNode* root, bool &ans){
        
        if(ans || root == NULL)
            return;
        cout<<"ROOT "<<root->val<<endl;
        check(head,head,root,ans);
        
        forevery(head,root->left,ans);
        forevery(head,root->right,ans);
    }
    
    void check(ListNode* head, ListNode* ptr,TreeNode* root,bool &done){
        
        if(done)
            return;
        
        if(ptr == NULL){
            done = true;
            return;
        }
        cout<<ptr->val<<endl;
        if(root==NULL){
            return;
        }
        
        if(root->val != ptr->val){
            return;
        }
        else{
            check(head,ptr->next,root->left,done);
            check(head,ptr->next,root->right,done);
        }
        
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        if(head == NULL)
            return true;
        
        bool ans = false,cont=false;
        forevery(head,root,ans);
        
        return ans;
        
    }
};