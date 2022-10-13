class Solution {
public:
    
    bool isShipped(vector<int>& nums, int cap, int days){
        //cout<<cap<<endl;
        int n = nums.size();
        int sum = 0;
        int cnt =1;
        for(int i=0;i<n;i++){
            if(nums[i]>cap)
                return false;
            sum += nums[i];
            if(sum > cap){
                sum = nums[i];
                cnt++;
            }
            //cout<<sum<<"-"<<cnt<<" ";
        }
        //cout<<endl<<cnt<<endl;
        if(cnt <= days)
            return true;
        return false;
        
    }
    
    
    int shipWithinDays(vector<int>& nums, int days) {
        int sm = accumulate(nums.begin(),nums.end(),0);
        int l = 1, r = sm;
        while(l<r){
            int mid = l + (r-l)/2;
            if(isShipped(nums,mid,days))
                r = mid;
            else
                l = mid+1;
        }
        return l;
    }
};