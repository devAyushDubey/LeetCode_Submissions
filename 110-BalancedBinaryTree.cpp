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
    bool isBalanced(TreeNode* root) {
        check(root);
        return flag;
    }
public:
    void check(TreeNode* root){
        if(!flag)
            return;
        if(root==NULL)
            return;
        if(diff(height(root->left,0),height(root->right,0)) > 1)
            flag = false;
           
        check(root->left);
        check(root->right);
    }
public:
    int diff(int a, int b){
        return max(a,b) - min(a,b);
    }
public:
    int height(TreeNode * root, int len){
        if(root == NULL)
            return len;
        len++;
        int l = height(root->left,len);
        int r = height(root->right,len);
        return max(l,r);
    }
};