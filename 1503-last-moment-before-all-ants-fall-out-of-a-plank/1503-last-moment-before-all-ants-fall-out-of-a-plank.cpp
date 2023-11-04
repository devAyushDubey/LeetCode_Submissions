class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int ans = 0;
        int m = left.size(), k = right.size();
        
        for(int i=0;i<m;i++) ans = max(ans,left[i]);
        
        for(int i=0;i<k;i++) ans = max(ans,n-right[i]);
        
        return ans;
    }
};