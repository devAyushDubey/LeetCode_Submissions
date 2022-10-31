#define MOD 1000000007
class Solution {
public:

    long long compound(int a,long long n){
        if(n==0)
            return 1;
        
        long long f = compound(a,n/2);
        long long res = (f*f)%MOD;
        if(n%2!=0)
            res = (res*a)%MOD;
        return res;
    }
        
    int countGoodNumbers(long long n) {
        
        int ret = 0;
        
        if(n%2==0){
            long long four = compound(4,n/2);
            long long five = compound(5,n/2);
            long long ans = (four*five)%MOD;
            ret = (int) ans;
        }
        else{
            long long four = compound(4,n/2);
            long long five = compound(5,(n/2)+1);
            long long ans = (four*five)%MOD;
            ret = (int) ans;
        }
        return ret;
    }
};