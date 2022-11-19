class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n = temp.size();
        vector<pair<int,int>> stk;
        vector<int> ans (n,0);
        stk.push_back({temp[0],0});
        
        for(int i=1;i<n;i++){
            while(stk.size() != 0 && temp[i] > stk.back().first){
                ans[stk.back().second] = i - stk.back().second;
                stk.pop_back();
            }
            stk.push_back({temp[i],i});
        }
        
        ans[n-1] = 0;
        return ans;
    }
};