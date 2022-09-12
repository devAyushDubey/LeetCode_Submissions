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
    int max_d = 0;
public:
    void max_depth(TreeNode* root, int length = 0){
        if(root==NULL)
            return;
        length++;
        max_d = max(length,max_d);
        max_depth(root->left,length);
        max_depth(root->right,length);
    }
public:
    int maxDepth(TreeNode* root) {
        max_depth(root);
        return max_d;
            
    }
};