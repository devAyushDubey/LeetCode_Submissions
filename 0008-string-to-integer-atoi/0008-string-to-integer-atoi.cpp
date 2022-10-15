class Solution {
public:
    int myAtoi(string s) {
        
        int n = s.length();
        int i = 0;
        
        while(s[i]==' ')
            i++;
        
        long long num = 0;
        int ans = 1;
        bool flag = false;
        
        if(s[i]=='-'){
            ans = -1;
            i++;
        }else if(s[i]=='+')
            i++;
        
        while(i<n){
            
            int j = (int)s[i];
            
            if(j < 48 || j>57)
                break;
            
            num = (num*10) + (j-48);
            
            if(num>INT_MAX){
                num = INT_MAX;
                flag = true;
                //cout<<num<<" "<<INT_MAX;
                break;
            }
            //cout<<num<<endl;
            i++;
        }
        
        if(num == INT_MAX && ans<0){
            if(flag)
                return INT_MIN;
        }
            
        
        ans = ans * (int)num;
        return ans;
    }
};