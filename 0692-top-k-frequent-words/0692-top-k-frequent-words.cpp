class Solution {
public:
    
    static bool cmp(pair<string,int> &a, pair<string,int> &b){
        
        if(a.second == b.second && a.first>b.first)
            return false;
        else if(a.second == b.second && a.first<b.first)
            return true;
        
        return a.second >= b.second;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> mp;
        
        for(auto it: words){
            mp[it]++;
        }
        
        vector<pair<string,int>> vec;
        for(auto it: mp){
            vec.push_back(it);
        }
        
        sort(vec.begin(),vec.end(),cmp);
        //for(auto it:vec) cout<<it.first<<" "<<it.second<<" ";
        words.clear();
        for(int i =0;i<k;i++){
            words.push_back(vec[i].first);
        }
        
        return words;
    }
};