class Solution {
    
public:
    int climbStairs(int n) {
        
        vector<int> vec(n+1);
        
        return climbStair(n, vec);
        
    }
    
    int climbStair(int n,vector<int>& v){
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        
        if(v[n]>0)
            return v[n];
        
        int s = climbStair(n-1,v) + climbStair(n-2,v);
        v[n] = s;
        return s;
    }
};