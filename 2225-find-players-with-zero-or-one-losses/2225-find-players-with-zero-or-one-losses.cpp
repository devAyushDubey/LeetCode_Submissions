class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int,int> win;
        map<int,int> lose;
        
        for(auto it: matches)
            lose[it[1]]++;
        
        for(auto it: matches){
            if(!lose[it[0]])
                win[it[0]]++;
        }
        
        vector<vector<int>> ans (2);
        for(auto it: win)
            ans[0].push_back(it.first);
        for(auto it: lose){
            if(it.second == 1)
                ans[1].push_back(it.first);
        }
        
        
        return ans;
    }
};