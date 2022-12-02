class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.length(), n= word2.length();
        if(m!=n)
        return false;
        unordered_set<char> st;
        vector<int> freq1(26,0), freq2(26,0);
        for(int i=0;i<m;i++)
        {
            st.insert(word1[i]);
            freq1[word1[i]-'a']++;
        }
        for(int i=0;i<n;i++ )
        {
            // check if characters in word2 are same as the characters in word1
            if(st.find(word2[i])==st.end())
            return false;
            freq2[word2[i]-'a']++;
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        //return true if the frequency arrays of both word1 and word2 are equal else return false.
        return freq1==freq2;
    }
};