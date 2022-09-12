class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        if(nums.size()==1)
            return nums[0];
        for(int i =0;i<nums.size();i++){
            if(mp.find(nums[i]) != mp.end()){
                mp[nums[i]]++;
                if(mp[nums[i]] > nums.size()/2)
                    return nums[i];
            }
            else
                mp.insert({nums[i],1});
        }
        return 0;
    }
};