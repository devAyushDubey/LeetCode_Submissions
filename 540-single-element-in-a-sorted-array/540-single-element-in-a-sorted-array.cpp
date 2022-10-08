class Solution {
public:
    
    int search(vector<int> nums, int l, int r){
        //cout<<l<<" "<<r<<endl;
        if(l<=r){
            int mid = l + (r-l)/2;
            //cout<<mid<<endl;
            if(mid%2 == 0){
                if(nums[mid] == nums[mid+1])
                    return search(nums,mid+1,r);
                return search(nums,l,mid-1);
            }
            else{
                if(nums[mid] == nums[mid-1])
                    return search(nums,mid+1,r);
                return search(nums,l,mid-1);
            }
        }
        return nums[l];
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size()-1;
        
        if(n<0)
            return 0;
        
        return search(nums,0,n-1);
    }
};