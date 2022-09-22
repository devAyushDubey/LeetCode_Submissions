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
    
    TreeNode* createTree(vector<int> postorder, int postStart, int postEnd, vector<int> inorder, int inStart, int inEnd, unordered_map<int,int> &inMap){
        
        if(postStart < postEnd || inStart > inEnd)
            return NULL;
        
        //cout<<postStart<<" "<<postEnd<<" "<<inStart<<" "<<inEnd<<endl;
        
        TreeNode* root = new TreeNode(postorder[postStart]);
        
        int in = inMap[root->val];
        int len = inEnd - in;
        
        root->left = createTree(postorder, postStart - len - 1, postEnd,inorder, inStart, in - 1, inMap);
        root->right = createTree(postorder, postStart - 1, postStart - len,inorder, in + 1, inEnd,inMap);
        
        
        return root;
        
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int,int> inMap;
        
        for(int i =0;i<inorder.size();i++)
            inMap[inorder[i]] = i;
        
        // reverse(postorder.begin(),postorder.end());
        
        TreeNode* root = createTree(postorder, postorder.size()-1, 0, inorder, 0, inorder.size()-1,inMap);
        
        return root;
    }
};