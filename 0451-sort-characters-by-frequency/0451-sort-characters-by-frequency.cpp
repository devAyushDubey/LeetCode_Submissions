class Solution {
public:
    
    static bool cmp(pair<char,int> &a, pair<char,int> &b){
        return a.second > b.second;
    }
    
    string frequencySort(string s) {
        int n = s.length();
        map<char,int> mp;
        for(int i=0;i<n;i++)
            mp[s[i]]++;
        
        vector<pair<char,int>> vec;
        for(auto& it : mp){
            //cout<<it.first<<" "<<it.second<<endl;
            vec.push_back(it);
        }
        
        sort(vec.begin(),vec.end(),cmp);
        
        string st = "";
        cout<<endl;
        for(auto& it: vec){
            //cout<<it.first<<" "<<it.second<<endl;
            for(int i=0;i<it.second;i++)
                st.push_back(it.first);
        }
        
        return st;
    }
};