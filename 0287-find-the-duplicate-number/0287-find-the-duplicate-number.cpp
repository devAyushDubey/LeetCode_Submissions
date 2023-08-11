class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,bool> mp;
        int ans = 0;
        for(auto it: nums){
            if(mp[it]) {
                ans = it;
                break;
            }
            mp[it] = true;
        }
        return ans;
    }
};