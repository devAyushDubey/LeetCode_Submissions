class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size=0;
        int i=0;

        while(size<k){
            if(isdigit(s[i])){
                size *= s[i]-'0';
            }
            else{
                size++;
            }
            i++;
        }

        for(int j=i-1;j>=0;j--){
            if(isdigit(s[j])){
                size /= s[j]-'0';
                k %=size;
            }
            else{
                if(k==0 || k==size){
                    return std::string(1,s[j]);
                }
                size--;
            }
        }
        return "";
        
    }
};