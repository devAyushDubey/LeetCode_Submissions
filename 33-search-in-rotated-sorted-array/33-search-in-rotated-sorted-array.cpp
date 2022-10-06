class Solution {
public:
    
    int bSearch(vector<int>& nums, int target, int l, int r){
        cout<<l<<" "<<r<<endl;
        if(l<=r){
            int mid = l + (r-l)/2;
            cout<<mid<<endl;
            if(nums[mid] == target)
                return mid;
            else if(nums[l] < nums[mid] || mid==l){
                if(target >= nums[l] && target < nums[mid])
                    return bSearch(nums,target,l,mid-1);
                return bSearch(nums,target,mid+1,r);
            }
            else{
                if(target > nums[mid] && target <= nums[r])
                    return bSearch(nums,target,mid+1,r);
                return bSearch(nums,target,l,mid-1);
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size()-1;
        return bSearch(nums,target,0,n);
    }
}; 