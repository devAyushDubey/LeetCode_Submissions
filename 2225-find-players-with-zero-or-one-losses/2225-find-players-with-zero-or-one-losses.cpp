class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        vector<vector<int>> ans(2);
        map<int,int> m;
        
        for(auto v : matches)
        {
            m[v[0]] += 0;
            m[v[1]]++;
        }
        
        for(auto i : m)
        {
            if(i.second == 0)
            {
                ans[0].push_back(i.first);
            }
            else if(i.second == 1)
            {
                ans[1].push_back(i.first);
            }
        }
        
        return ans;
    }
};