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
    int minn = INT_MAX;
public:
    int minDepth(TreeNode* root) {
        minLength(root,0);
        if(minn==INT_MAX)
            return 0;
        return minn;
    }
    
    void minLength(TreeNode* root, int length){
        if(root==NULL)
            return; 
        length++;
        if(length>minn)
            return;
        if(root->left == NULL && root->right == NULL){
            minn = min(minn,length);
            return;
        }
        
        minLength(root->left, length);
        minLength(root->right, length);
    }
};