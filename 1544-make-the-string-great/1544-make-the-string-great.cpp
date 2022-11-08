class Solution {
public:
    string makeGood(string s) {
        int i=0;
        while(i<s.length()){
            if(((s[i]>='a' && s[i]<='z') && (s[i+1]>='A' && s[i+1]<='Z')) && (s[i]-32==s[i+1])){
                s.erase(i,2);
                i=0;
            }
            else if(((s[i]>='A' && s[i]<='Z') && (s[i+1]>='a' && s[i+1]<='z')) && (s[i]==s[i+1]-32)){
                s.erase(i,2);
                i=0;
            }
            else{
                i++;
            }
        }
        if(s.empty()){
            return "";
        }
        return s;
    }
};