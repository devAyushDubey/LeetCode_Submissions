class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int sz = nums.size(), mnAvgDif = INT_MAX, idx = 0;
        long long frontSum = 0, endSum = 0;
        for(int n : nums)
            endSum += n;

        for(int i = 0; i < sz; ++i)
        {
            frontSum += nums[i];
            endSum -= nums[i];
            int a = frontSum / (i+1);
            int b = (i == sz-1) ? 0 : endSum / (sz-i-1);

            if(abs(a-b) < mnAvgDif)
            {
                mnAvgDif = abs(a-b);
                idx = i;
            }
        }
        return idx;
    }
};