class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        for(auto it: nums)
            mp[it]++;
        
        vector<int> ans;
        for(int i =1;i<=nums.size();i++){
            if(mp[i] == 2)
                ans.push_back(i);
        }
        for(int i =1;i<=nums.size();i++){
            if(mp[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};