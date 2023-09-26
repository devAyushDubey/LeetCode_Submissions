class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n = str1.length();
        int m = str2.length();
        
        int dp[n+1][m+1];
        
        for(int i=0;i<m+1;i++) dp[0][i] = 0;
        for(int i=0;i<n+1;i++) dp[i][0] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1] +1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        int i = n;
        int j = m;
        string st;
        
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                st.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i][j-1] > dp[i-1][j]){
                    st.push_back(str2[j-1]);
                    j--;
                }
                else{
                    st.push_back(str1[i-1]);
                    i--;
                }
            }
        }
        
        while(i>0) st.push_back(str1[--i]);
        while(j>0) st.push_back(str2[--j]);
        
        reverse(st.begin(),st.end());
        
        return st;
    }
};