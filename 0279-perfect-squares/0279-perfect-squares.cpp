class Solution {
public:
    int numSquares(int n) {
        
        vector<int> sq (n+1,0);
        
        sq[0] = 0;
        sq[1] = 1;
        
        for(int i =2;i<=n;i++){
            
            int minn = INT_MAX;
            
            for(int j =1;j*j<=i;j++){
                int rem = i - (j*j);
                minn = min(minn,sq[rem]);
            }
            
            sq[i] = minn+1;
            
        }
        
        return sq[n];
    }
};