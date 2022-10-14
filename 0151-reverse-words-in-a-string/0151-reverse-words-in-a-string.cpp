class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        vector<string> ans;
        string st = "";
        
        while(s[i]==' ')
            i++;
        
        while(i<n){
            if(s[i]==' '){
                ans.push_back(st);
                st = "";
                while(s[i]==' ')
                    i++;   
                continue;
            }
            
            st = st + s[i];
            
            if(i==n-1)
                ans.push_back(st);
            
            i++;
        }
        
        reverse(ans.begin(),ans.end());
        
        st="";
        for(int i=0;i<ans.size();i++){
            if(i==ans.size()-1)
                st = st + ans[i];
            else
                st = st + ans[i] + " ";
        }
        
        return st;
    }
};