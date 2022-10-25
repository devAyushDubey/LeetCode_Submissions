class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string st1 = "";
        string st2 = "";
        
        for(auto it: word1)
            st1 += it;
        for(auto it: word2)
            st2 += it;
        
        return st1==st2;
    }
};