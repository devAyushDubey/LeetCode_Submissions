class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        
        for(auto it: nums)
            freq[it]++;
        
        int n = nums.size();
        int minn = n/3;
        nums.clear();
        for(auto &it: freq){
            if(it.second > minn)
                nums.push_back(it.first);
        }
        
        return nums;
    }
};