class Solution {
public:
    string convertToTitle(int columnNumber, string st = "") {
        if(columnNumber> 26){
            if(columnNumber % 26 ==0){
                st = convertToTitle((columnNumber/26)-1,st);
                columnNumber = 26;
            }
            else{
                st = convertToTitle(columnNumber/26,st);
                columnNumber = columnNumber % 26;
            }
        }
        
        st = st + char(columnNumber+64);
        return st;
    }
};