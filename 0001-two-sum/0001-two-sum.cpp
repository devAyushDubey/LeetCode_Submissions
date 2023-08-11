class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
            nums[i] = target - nums[i];
        }
        
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]] && mp[nums[i]] != i) {
                ans = {i,mp[nums[i]]};
                break;
            }
        }
        
        return ans;
    }
};