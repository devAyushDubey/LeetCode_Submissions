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
    void preT(TreeNode* root,vector<int>& v){
        if(root == NULL)
            return;
        
        v.push_back(root->val);
        preT(root->left,v);
        preT(root->right,v);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        preT(root,vec);
        return vec;
    }
};