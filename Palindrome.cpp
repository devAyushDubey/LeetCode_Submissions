class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0)
            return false;
        
        vector<int> rev;
        int t = x;
        
        while(t>0){
            rev.push_back(t%10);
            t /= 10;
        }
        
        reverse(rev.begin(),rev.end());
        
        for(int i=0;i<rev.size();i++){
            if(rev[i]!=x%10)
                return false;
            x /= 10;
        }
        
        return true;
            
    }
};