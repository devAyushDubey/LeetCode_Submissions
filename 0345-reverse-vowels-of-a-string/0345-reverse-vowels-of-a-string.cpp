class Solution {
public:
    string reverseVowels(string s) {
        
        unordered_map<char,int> mp;
        vector<char> vec = {'a','e','i','o','u'};
        
        for(auto it: vec)
            mp[it]++;
        
        vector<char> vowels;
        for(auto it: s){
            if(mp[tolower(it)])
                vowels.push_back(it);
        }
        reverse(vowels.begin(),vowels.end());
        int i=0;
        for(auto &it: s){
            if(mp[tolower(it)])
                it = vowels[i++];
        }
        return s;
    }
};