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
    bool flag = true;
    
public:
    void isMirrorTree(TreeNode* p, TreeNode* q) {
        //cout<<p->val<<" "<<q->val<<" . ";
        if(p==NULL && q==NULL)
            return;
        
        if(!flag)
            return;
        
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)){
            flag = false;
            return;
        }
        
        
        if(p->val != q->val)
            flag = false;
        
        isMirrorTree(p->left,q->right);
        isMirrorTree(p->right,q->left);
        
        return;
    }
public:
    bool isSymmetric(TreeNode* root) {
        isMirrorTree(root->left,root->right);
        return flag;
    }
};