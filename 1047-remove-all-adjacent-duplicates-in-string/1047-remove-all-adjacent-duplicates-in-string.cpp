class Solution {
public:

    
    string removeDuplicates(string s) {
        
        int n = s.length();
        string ans;
        for(int i=0;i<s.length();i++){
            
            int m = ans.length();
            if(m && (ans[m-1] == s[i])){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};