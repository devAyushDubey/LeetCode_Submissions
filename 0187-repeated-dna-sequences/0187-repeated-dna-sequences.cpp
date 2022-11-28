class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_map<string,int> mp;
        
        int n = s.length();
        vector<string> ans;
        
        if(n < 10)
            return ans;
        
        string st = s.substr(0,10);
        mp[st]++;
        
        for(int i = 10;i<n;i++){
            st = st.substr(1,9);
            st += s[i];
            mp[st]++;
        }
        
        for(auto it: mp){
            if(it.second >= 2)
                ans.push_back(it.first);
        }
        
        return ans;
    }
};