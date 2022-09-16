class Solution {
public:
    
    vector<vector<int>> ans;
    
    void uniquePerm(int n,int r,map<int,int> &mp,vector<int> perm){
        
        if(r==n){
            ans.push_back(perm);
            return;
        }
        
        for(auto &it: mp){
            if(it.second > 0){
                it.second--;
                perm.push_back(it.first);
                uniquePerm(n,r+1,mp,perm);
                perm.pop_back();
                it.second++;
            }
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        int n = nums.size();
        map<int,int> mp;
        
        for(auto it: nums)
            mp[it]++;
        
        vector<int> perm;
        
        uniquePerm(n,0,mp,perm);
        
        return ans;
        
    }
};