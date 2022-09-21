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
    
    TreeNode* createTree(vector<int>& preorder, int preStart, int preEnd, int inStart, int inEnd, map<int,int> &inMap){
        
        
        if(preStart > preEnd || inStart > inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int in = inMap[root->val];
        int len = in - inStart;
        root->left = createTree(preorder, preStart + 1, preStart + len, inStart, in - 1,inMap);
        root->right = createTree(preorder, preStart + len + 1, preEnd, in + 1, inEnd, inMap);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int> inMap;
        
        for(int i=0;i<inorder.size();i++)
            inMap[inorder[i]] = i;
        
        TreeNode* root = createTree(preorder, 0, preorder.size()-1, 0, inorder.size()-1,inMap);
        
        return root;
    }
};