class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        std::vector<TreeNode*> parents;
        int pre_idx = 0;
        int in_idx = 0;
        
        TreeNode dummy(-1); // placeholder
        TreeNode** current = &(dummy.left);
        
        while(pre_idx < preorder.size())
        {
            while(pre_idx < preorder.size())
            {
                *current = new TreeNode(preorder[pre_idx++]);
                parents.push_back(*current);
                current = &(parents.back()->left);

                if(parents.back()->val==inorder[in_idx])
                    break;
            }

            while(!parents.empty() && parents.back()->val==inorder[in_idx])
            {
                current = &(parents.back()->right);
                parents.pop_back();
                ++in_idx;
            }
        }

        return dummy.left;
    }
};