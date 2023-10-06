class Solution {
public:
    int integerBreak(int n) {
        vector<vector<int>> dp(n,vector<int> (n+1,1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0)
                dp[i][j]=0;
                if(j==0)
                dp[i][j]=1;
            }
        }
        for(int i=2;i<n;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(i<=j)
                {
                    dp[i][j]=max(i*dp[i][j-i],dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }

            }


        }
        return dp[n-1][n];

        
    }
};