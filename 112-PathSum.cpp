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
    bool flag = false;
    int sum=0;
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        sum = targetSum;
        check(root,0);
        return flag;
    }
    
    void check(TreeNode* root, int currsum){
        if(flag) return;
        
        if(root==NULL) return;
        
        currsum += root->val;
        
        if(root->left == NULL && root->right == NULL){
            if(currsum == sum)
                flag = true;
        }
        
        check(root->left,currsum);
        check(root->right,currsum);
    }
};