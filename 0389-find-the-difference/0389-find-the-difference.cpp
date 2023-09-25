class Solution {
public:
    char findTheDifference(string s, string t) {
        
        map<char,int> count;
        
        for(auto it: s) count[it]++;
        
        int i = 0;
        for(i=0;i<t.length();i++){
            if(count[t[i]])
                count[t[i]]--;
            else
                break;
        }
        
        return t[i];
    }
};