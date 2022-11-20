/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    void allNodes(Node* root, vector<vector<int>> &ans, int level){
        
        if(root==NULL)
            return;
        
        int n = ans.size();
        if(level >= n){
            vector<int> ne;
            ne.push_back(root->val);
            ans.push_back(ne);
        }
        else{
            ans[level].push_back(root->val);
        }
        
        for(auto it: root->children)
            allNodes(it,ans,level+1);
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;
        
        allNodes(root,ans,0);
        
        return ans;
        
    }
};