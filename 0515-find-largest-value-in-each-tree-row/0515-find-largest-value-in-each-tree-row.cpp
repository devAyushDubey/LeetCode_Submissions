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
    
    int height = 0;
    
    void larVal(TreeNode* root, int lvl, vector<int>& ans) {
        
        if(root == NULL)
            return;
        
        ans[lvl] = max(ans[lvl],root->val);
        height = max(height,lvl);
        
        larVal(root->left, lvl+1, ans);
        larVal(root->right, lvl+1, ans);
        
    }
    
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> ans(10001,INT_MIN);
        vector<int> t_ans;
        
        larVal(root,1,ans);
        
        for(int i=1;i<=height;i++)
            t_ans.push_back(ans[i]);
        
        return t_ans;
        
        
    }
};