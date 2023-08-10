class Solution {
public:
    
    bool ans = false;
    
    bool search(vector<int>& nums, int target) {
        
        BinarySearch(nums, target, 0, nums.size()-1);
        return ans;
        
    }
    
    void BinarySearch(vector<int>& nums, int target, int l, int r) {
        
        if(l>r) return;
        
        int mid = l + (r-l)/2;
        
        if(nums[mid] == target){
            ans = true;
            return;
        }
        else if((nums[l] == nums[mid]) && (nums[r]==nums[mid])){
            BinarySearch(nums,target,l+1,r-1);
        }
        else if(nums[l]<=nums[mid]){ 
            if((nums[l] <= target) && (target < nums[mid]))
                BinarySearch(nums,target,l,mid-1);
            else
                BinarySearch(nums,target,mid+1,r);
        }
        else{
            if((nums[mid] < target) && (target <= nums[r]))
                BinarySearch(nums,target,mid+1,r);
            else
                BinarySearch(nums,target,l,mid-1);
        }
    }
};