class Solution {
public:
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int l = 1,r=1e9;
        int n = bloomDay.size();
        
        long long check = (long long)k*(long long)m;
        if(check > n)
            return -1;
        
        while(l<r){
            int mid = l + (r-l)/2;
            int flow = 0,bouq=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i] > mid)
                    flow = 0;
                else if(++flow >= k){
                    bouq++;
                    flow = 0;
                }
            }
            if(bouq < m)
                l = mid+1;
            else
                r = mid;
        }
        
        return l;
    }
};