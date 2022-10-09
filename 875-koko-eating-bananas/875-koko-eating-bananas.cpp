class Solution {
public:
    
    int calcHours(vector<int>& piles, int n){
        //float f = n;
        int sum = 0;
        for(int i =0;i<piles.size();i++){
            int amt = (int)ceil((piles[i]*1.0)/n); 
            sum+=amt;
        }
        return sum;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int l = 0;
        int r = piles[piles.size()-1];
        int ans = r;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(mid <= 0)
                break;
            //cout<<l<<" "<<mid<<" "<<r<<endl;
            int hours = calcHours(piles,mid);
            //cout<<hours<<endl;
            if(hours <= h){
                ans = min(ans,mid);
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};