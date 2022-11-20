class Solution {
public:
    int calculate(string s) {
        stack<pair<int,int>> st;    
        long res = 0;
        int sign = 1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0') {                        // build number
                long num = 0;
                while(i < s.size() and s[i]>='0')
                    num = 10*num + s[i++]-'0';
                i--;
                res += num * sign;
                sign = 1;                           // reset sign to +ve
            }
            else if(s[i] == '(')
                st.push({res, sign}), res = 0, sign = 1; // save sign , res and reset the both
            else if(s[i] == ')')
                res = st.top().first + st.top().second*res, st.pop();  // add previous sum with current sum and pop previous res
            else if(s[i] == '-')
                sign *= -1;                        // toggle sign
        }
        return res;
    }
};