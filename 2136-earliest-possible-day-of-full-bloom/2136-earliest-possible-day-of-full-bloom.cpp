class Solution {
public:
    
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        return (a.second) > (b.second);
    }
    
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<pair<int,int>> vec;
        int n = plantTime.size();
        
        for(int i =0;i<n;i++)
            vec.push_back({plantTime[i],growTime[i]});
        
        sort(vec.begin(),vec.end(),cmp);
        
        int bloomDay = 0, seedDay = 0;
        for(auto it: vec){
            
            bloomDay = max(bloomDay, seedDay + it.first + it.second);
            
            seedDay += it.first;
        }
        
        return bloomDay;
    }
};