class Solution {
public:
    
    vector<vector<int>> ans;
    
    void subsetsGen(vector<int>& subs, int i, vector<int> temp) {
        
        if(i == subs.size()){
            ans.push_back(temp);
            return;
        }
        
        subsetsGen(subs,i+1,temp);
        temp.push_back(subs[i]);
        subsetsGen(subs,i+1,temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        subsetsGen(nums,0,{});
        return ans;
    }
};