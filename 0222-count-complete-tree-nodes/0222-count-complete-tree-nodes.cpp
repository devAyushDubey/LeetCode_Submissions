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
    
    int treeNodes(TreeNode* root){
        
        if(root == NULL)
            return 0;
        
        TreeNode* ptr = root;
        
        
        int leftHeight=0;
        while(ptr -> left != NULL){
            leftHeight++;
            ptr = ptr->left;
        }    
        
        int rightHeight=0;
        while(ptr -> right != NULL){
            rightHeight++;
            ptr = ptr->right;
        }    
        
        if(leftHeight == rightHeight)
            return pow(2,leftHeight);
        
        return 1 + treeNodes(root->left) + treeNodes(root->right);

    }
    
    
    int countNodes(TreeNode* root) {
        
        return treeNodes(root);
    }
};