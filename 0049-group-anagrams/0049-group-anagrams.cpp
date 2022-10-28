class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
            string st = strs[i];
            sort(st.begin(),st.end());
            if(mp.find(st) != mp.end())
                mp[st].push_back(strs[i]);
            else
                mp[st] = {strs[i]};
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};