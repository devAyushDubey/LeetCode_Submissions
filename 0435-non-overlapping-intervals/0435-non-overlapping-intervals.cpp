class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int> &b){
        
        if(a[0] == b[0]) return a[1] < b[1];
        
        return a[0] < b[0];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        
        sort(intervals.begin(),intervals.end(),cmp);
        
        
        int ans = 0;
        int last = INT_MIN;
        for(auto it: intervals){
            
            if(last <= it[0])
                last = it[1];
            else{
                ans++;
                if(last > it[1])
                    last = it[1];
            }
            
        }
        
        return ans;
        
        
    }
};