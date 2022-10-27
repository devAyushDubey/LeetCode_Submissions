class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        vector<pair<int,int>> ones1;
        vector<pair<int,int>> ones2;
        
        int n = img1.size();
        
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(img1[i][j] == 1)
                    ones1.push_back(make_pair(i,j));
                if(img2[i][j] == 1)
                    ones2.push_back(make_pair(i,j));
            }
        }
        
        map<pair<int,int>,int> mp;
        int ans = 0;
        
        for(auto it: ones1){
            for(auto jt: ones2){
                mp[make_pair(jt.second-it.second,jt.first-it.first)]++;
                ans = max(ans,mp[make_pair(jt.second-it.second,jt.first-it.first)]);
            }
        }
        
        return ans;
    }
};