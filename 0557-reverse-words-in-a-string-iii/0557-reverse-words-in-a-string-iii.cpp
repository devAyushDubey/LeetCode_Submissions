class Solution {
public:
    string reverseWords(string s) {
        
        string ans = "";
        
        stack<char> stk;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                string str = "";
                while(!stk.empty()){
                    str += stk.top();
                    stk.pop();
                }
                
                if(str != ""){
                    if(ans=="")
                        ans += str;
                    else
                        ans += (" " + str);
                }
                
                continue;
            }
            
            stk.push(s[i]);
            
        }
        
        string str = "";
        while(!stk.empty()){
            str += stk.top();
            stk.pop();
        }

        if(str != ""){
            if(ans=="")
                ans += str;
            else
                ans += (" " + str);
        }
        
        return ans; 
    }
};