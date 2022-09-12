class Solution {
public:
    bool isPalindrome(string s) {
        int c=0;
        for(int i=0;i<s.length();i++)
            s[i] = tolower(s[i]);
        for(int i =0;i<s.length();i++){
            if(!isalnum(s[i])){
                s[i] = ' ';
                c++;
            }
            
        }
        remove(s.begin(),s.end(),' ');
        s.resize(s.length()-c);
        if(s=="")
            return true;
        //st = st + "a";
        for(int i=0;i<=s.length()/2;i++){
            if(s[i] != s[s.length()-i-1])
                return false;
        }
        return true;
    }
};