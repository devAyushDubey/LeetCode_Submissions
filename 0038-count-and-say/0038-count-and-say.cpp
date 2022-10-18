class Solution {
public:
    
    string say(string s){
        int l = s.length();
        int i = 0;
        vector<pair<int,char>> freq;
        while(i<l){
            char st = s[i];
            int cnt = 0;
            while(st==s[i]){
                cnt++;
                i++;
            }
            freq.push_back(make_pair(cnt,s[i-1]));
        }
        string ans = "";
        for(auto it: freq){
            ans += to_string(it.first);
            ans.push_back(it.second);
        }
        cout<<ans<<endl;
        return ans;
    }
    
    string countAndSay(int n) {
        
        string st = "1";
        for(int i=2;i<=n;i++){
            st = say(st);
        }
        return st;
    }
};