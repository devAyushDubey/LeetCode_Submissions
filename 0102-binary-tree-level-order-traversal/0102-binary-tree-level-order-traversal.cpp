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
    
    vector<vector<int>> data;
    
    void lvlT(TreeNode* node, int lvl) {
        
        if(node == NULL) return;
        
        if(lvl > data.size()) data.push_back({node->val});
        else data[lvl-1].push_back(node->val);
        
        lvlT(node->left,lvl+1);
        lvlT(node->right,lvl+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        lvlT(root,1);
        return data;
    }
};