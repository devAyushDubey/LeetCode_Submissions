class Solution {
public:
    int func(int ind,vector<vector<int>>&job, vector<int>& s, int sz,vector<int>&dp)
    {
        if(ind>=sz)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int i=lower_bound(s.begin(),s.end(),job[ind][1])-s.begin();
        int pick=job[ind][2]+func(i,job,s,sz,dp);
        int npick=func(ind+1,job,s,sz,dp);
        return dp[ind]=max(pick,npick);
    }
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        vector<vector<int>>sol;
        int sz=s.size();
        vector<int>dp(sz+1,-1);
        for(int i=0;i<sz;i++) sol.push_back({s[i],e[i],p[i]});
        sort(sol.begin(),sol.end());
        sort(s.begin(),s.end());
        return func(0,sol,s,sz,dp);
    }
};