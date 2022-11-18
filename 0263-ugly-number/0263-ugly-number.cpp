class Solution {
public:
    bool isUgly(int n) {
        if(n<=0)
            return false;
        while(n%2==0){
            n = n/2;
        }
        for(int i=3;i<=sqrt(n);i+=2){
            if(n%i==0 && i>5)
                return false;
            while(n%i==0)
                n=n/i;
        }
        if(n>5)
            return false;
        return true;
    }
};