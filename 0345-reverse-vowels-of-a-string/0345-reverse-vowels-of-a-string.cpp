class Solution {
public:
    string reverseVowels(string s) {
        
        int n = s.length();
        
        unordered_map<char,int> mp;
        vector<char> vec = {'a','e','i','o','u'};
        
        for(auto it: vec)
            mp[it]++;
        
        int l=0,r=n-1;
        while(l<=r){
            while(l<n && !mp[tolower(s[l])])
                l++;
            while(r>0 && !mp[tolower(s[r])])
                r--;
            
            if(l>r)
                return s;
            
            char c = s[l];
            s[l] = s[r];
            s[r] = c;
            
            l++;
            r--;
        }
        return s;
    }
};