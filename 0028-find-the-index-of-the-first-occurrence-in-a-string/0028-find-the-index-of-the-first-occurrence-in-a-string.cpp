class Solution {
public:
    int strStr(string haystack, string needle) {
        int i =0;
        if(haystack.length() < needle.length())
            return -1;
        while(i<=(haystack.length()-needle.length())){
            if(haystack[i]==needle[0]){
                string temp = haystack.substr(i,needle.length());
                if(temp == needle)
                    return i;
            }
            i++;
        }
        return -1;
    }
};