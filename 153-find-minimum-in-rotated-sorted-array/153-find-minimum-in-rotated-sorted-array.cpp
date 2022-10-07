class Solution {
public:
    
    int bSearch(vector<int>& nums, int l, int r){
        cout<<l<<" "<<r<<endl;
        if(l<r){
            int mid = l + (r-l)/2;
            cout<<mid<<endl;
            if(nums[l] < nums[r])
                return nums[l];
            else if(nums[l] <= nums[mid])
                return bSearch(nums,mid+1,r);
            else
                return bSearch(nums,l,mid);
        }
        return nums[l];
    }
    
    int findMin(vector<int>& nums) {
        
        int n = nums.size()-1;
        
        if(n<0)
            return 0;
        
        return bSearch(nums,0,n);
    }
};