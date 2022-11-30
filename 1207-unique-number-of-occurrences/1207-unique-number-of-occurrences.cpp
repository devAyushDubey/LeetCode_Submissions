class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int,int> freq;
        unordered_map<int,int> unic;
        
        for(auto it: arr)
            freq[it]++;
        
        for(auto it: freq){
            if(unic[it.second])
                return false;
            unic[it.second]++;
        }
        
        return true;
    }
};