class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        map<char,int> lastIndex;
        map<char,bool> isAdded;
        
        for(int i=0;i<s.length();i++) lastIndex[s[i]] = i;
        
        vector<char> stk;
        
        for(int i=0;i<s.length();i++) {
            if(isAdded[s[i]])
                continue;
            while(stk.size()>0 && s[i] < stk.back() && i < lastIndex[stk.back()]){
                isAdded[stk.back()] = false;
                stk.pop_back();
            }
            stk.push_back(s[i]);
            isAdded[s[i]] = true;
        }
        
        string ans = "";
        
        for(auto it: stk) ans += it; 
        
        return ans;
    }
};