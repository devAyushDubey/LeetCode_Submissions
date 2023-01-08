class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        int ans = 1;
        
        for(int i=0;i<n;i++){
            map<double,int> mp;
            int mx = 0;
            for(int j = i+1;j<n;j++){
                double m = (points[j][1] - points[i][1])/((double)(points[j][0]-points[i][0]));
                if(points[j][0] == points[i][0]){
                    mp[abs(m)]++;
                    mx = max(mx,mp[abs(m)]);
                    continue;
                }
                mp[m]++;
                mx = max(mx,mp[m]);
            }
            //cout<<endl;
            ans = max(mx+1,ans);
        }
        
        return ans;
    }
};