class Solution {
public:
    
    vector<vector<int>> getss(vector<int> nums){
        
        if (nums.size() == 0){
            vector<vector<int>> vec = {{}};
            return vec;
        }
        
        vector<vector<int>> ans;
        int last = nums.back();
        nums.pop_back();
        vector<vector<int>> rec = getss(nums);
        for(int i=0;i<rec.size();i++){
            sort(rec[i].begin(),rec[i].end());
            ans.push_back(rec[i]);
        }
        for(int i=0;i<rec.size();i++){
            vector<int> temp = rec[i];
            temp.push_back(last);
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        
        return ans;
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        
        vector<vector<int>> ans = getss(nums);
        
        map<vector<int>,int> mp;
        
        for(auto it: ans){
            mp[it]++;
        }
        
        ans.clear();
        
        for(auto it: mp){
            ans.push_back(it.first);
        }
        
        return ans;
        
    }
};