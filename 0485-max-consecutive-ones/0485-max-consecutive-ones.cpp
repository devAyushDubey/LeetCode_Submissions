class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int ones=0,max_ones=0;
        
        for(auto it: nums){
            if(it == 1) max_ones = max(max_ones,++ones);
            else ones=0;
        }
        
        return max_ones;
    }
};