class Solution {
public:
    
    int vowelCount(string s){
        
        int count = 0;
        for(auto it: s){
            if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u')
                count++;
        }
        return count;
    }
    
    bool halvesAreAlike(string s) {
        
        transform(s.begin(),s.end(),s.begin(), ::tolower);
        string s1 = s.substr(0,s.length()/2);
        string s2 = s.substr(s.length()/2,s.length()/2);
        
        if(vowelCount(s1) == vowelCount(s2))
            return true;
        
        return false;
        
    }
};