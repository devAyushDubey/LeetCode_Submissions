class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        long long disname = 0;
        
        vector<unordered_set<string>> vec(26); 
        for(string it: ideas){
            vec[it[0] - 'a'].insert(it.substr(1));
        }
        
        for(int i=0;i<25;i++){
            for(int j=i+1;j<26;j++){
                
                unordered_set<string> st;
                st.insert(vec[i].begin(),vec[i].end());
                st.insert(vec[j].begin(),vec[j].end());
                
                disname += (vec[i].size() - st.size())*(vec[j].size() - st.size());
            }
        }
        
        return disname*2;
    }
};