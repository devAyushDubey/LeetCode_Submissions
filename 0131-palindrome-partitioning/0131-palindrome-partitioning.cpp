class Solution {
public:
    
    vector<vector<string>> ans;
    
    bool isPalindrome(string str) {
        
        int n = str.length();

        for(int i=0;i<n/2;i++){
            if(str[i] != str[n-i-1])
                return false;
        }
        
        return true;
    }
    
    
    void partitionGen(string s, vector<string> tmp) {
        if(s.length() == 0){
            
            for(auto it: tmp){
                if(!isPalindrome(it))
                    return;
            }
            
            ans.push_back(tmp);
            return;
        }
        
        string st(1,s[0]);
        tmp.push_back(st);
        partitionGen(s.substr(1),tmp);
        
        tmp.pop_back();
        string lst = "";
        if(tmp.size() > 0){
            lst  = tmp.back();
            tmp.pop_back();
            
            tmp.push_back(lst+s[0]);
            partitionGen(s.substr(1),tmp);
        }
        
        
    }
    
    vector<vector<string>> partition(string s) {
        
        partitionGen(s,{});
        return ans;
        
    }
};