#include <math.h>
class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int> &b){
        float s1 = sqrt((float)((a[0]*a[0]) + (a[1]*a[1])));
        float s2 = sqrt((float)((b[0]*b[0]) + (b[1]*b[1])));
        
        return s1<s2;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        sort(points.begin(),points.end(),cmp);
        
        vector<vector<int>> ans;
        
        for(int i = 0;i<k;i++){
            ans.push_back(points[i]);
        }
        
        return ans;
    }
};