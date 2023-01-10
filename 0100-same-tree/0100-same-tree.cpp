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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==NULL && q==NULL)
            return true;
        
        if(!flag)
            return flag;
        
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)){
            flag = false;
            return flag;
        }
        
        
        if(p->val != q->val)
            flag = false;
        
        isSameTree(p->left,q->left);
        isSameTree(p->right,q->right);
        
        return flag;
    }
};