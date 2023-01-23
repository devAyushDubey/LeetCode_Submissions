class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> cnt (n, 0);
        
        for(auto it: trust){
            cnt[it[0]-1] = -1;
            cnt[it[1]-1]++;
        }
        
        for(int i=0;i<cnt.size();i++){
            if(cnt[i] == (n-1))
                return i+1;
        }
        
        return -1;
    }
};