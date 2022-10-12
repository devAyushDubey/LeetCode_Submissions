class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        int l = 1, r = mx;
        int mn_mid = mx;
        while(l<r){
            float mid = l + (r-l)/2;
            int sum = 0;
            for(int i=0;i<n;i++){
                sum += (int)ceil(nums[i]/mid);
            }
            cout<<l<<" "<<mid<<" "<<r<<" "<<sum<<endl;
            if(sum>threshold)
                l = mid + 1;
            else{
                r = mid;
                mn_mid = min(mn_mid,(int)mid);
            }
            cout<<mn_mid<<endl;
        }
        return l;
    }
};