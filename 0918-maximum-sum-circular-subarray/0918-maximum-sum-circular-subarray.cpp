class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int maxsum = INT_MIN;
        int currsum = INT_MIN+30006;
        int minsum = INT_MAX;
        int currsum2=INT_MAX-30006;      
        int total=0;
        for(int i=0;i<nums.size();i++)  {
            currsum = max(nums[i],currsum + nums[i]);
            maxsum = max(maxsum,currsum);
            currsum2 = min(currsum2 + nums[i],nums[i]);
            minsum = min(minsum,currsum2);
            total +=nums[i];
        }
        return maxsum>0?max(maxsum,total-minsum):maxsum;

    }
};