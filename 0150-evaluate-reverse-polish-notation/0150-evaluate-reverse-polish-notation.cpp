class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        vector<long long> st;
        long long ans = 0;

        if(tokens.size() == 1)
            return stoi(tokens[0]);
        
        for(auto it: tokens){
            
            if(it == "+" || it == "-" || it=="*" || it=="/"){
                
                if(it == "+"){
                    long long a = st.back();
                    st.pop_back();
                    long long b = st.back();
                    st.pop_back();
                    ans = a + b;
                    st.push_back(ans);
                }
                else if(it == "-"){
                    long long a = st.back();
                    st.pop_back();
                    long long b = st.back();
                    st.pop_back();
                    ans = b-a;
                    st.push_back(ans);
                }
                else if(it == "*"){
                    long long a = st.back();
                    st.pop_back();
                    long long b = st.back();
                    st.pop_back();
                    ans = a*b;
                    st.push_back(ans);
                }
                else{
                    long long a = st.back();
                    st.pop_back();
                    long long b = st.back();
                    st.pop_back();
                    ans = b/a;
                    st.push_back(ans);
                }
                
            }
            else{
                int a = stoi(it);
                long long t = a;
                st.push_back(t);
            }
        }
        
        return ans;
    }
};