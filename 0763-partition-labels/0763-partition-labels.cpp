class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n = s.length();
        unordered_map<char,int> mp;
        
        for(int i=0;i<n;i++)
            mp[s[i]] = i;
        
        int i=0;
        vector<int> ans;
        
        while(i<n){
            //cout<<i<<" "<<mp[s[i]]<<endl;
            if(mp.find(s[i]) != mp.end()){
                if(i == mp[s[i]]){
                    ans.push_back(1);
                    mp.erase(s[i]);
                    i++;
                }
                else{
                    int t = mp[s[i]];
                    //cout<<s[i]<<" "<<t<<endl;
                    for(int j = i;j<=t;j++)
                        t = max(t,mp[s[j]]);
                    ans.push_back(t-i+1);
                    mp.erase(s[i]);
                    i = t+1;
                }
            }
            else
                i++;
            
        }
        
        return ans;
    }
};