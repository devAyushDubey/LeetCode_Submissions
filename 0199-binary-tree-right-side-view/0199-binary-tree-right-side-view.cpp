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
    
    void rhs(TreeNode* root, int x, int lvl, vector<int>& data) {
        
        if(root == NULL)
            return;
        
        height = max(height,lvl);
        
        rhs(root->left,x-1,lvl+1,data);
        rhs(root->right,x+1,lvl+1,data);
        data[lvl] = root->val;
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> data(101,0);
        vector<int> ans;
        
        rhs(root,0,1,data);
        
        for(int i=1;i<=height;i++)
            ans.push_back(data[i]);
        
        return ans;
    }
};