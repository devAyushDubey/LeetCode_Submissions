class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = 0;
        
        for(auto it: nums) sum += it;
        
        if(sum+target < 0 || (sum+target)%2 != 0)
            return 0;

        int s1 = (sum+target)/2;
        
        int dp[n+1][s1+1];
        
        for(int i=1;i<s1+1;i++) dp[0][i] = 0;
        dp[0][0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=s1;j++){
                if(nums[i-1]<=j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        
        return dp[n][s1];
        
        
    }
};