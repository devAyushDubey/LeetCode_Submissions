class Solution {
public:
    
    int bSearch(vector<int> nums, int target,int left, int right){
        if(left<=right){
            int mid = left + (right-left)/2;
            
            if(nums[mid]<target)
                return bSearch(nums,target,mid+1,right);
            else if(nums[mid]>target)
                return bSearch(nums,target,left,mid-1);
            else
                return mid;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        return bSearch(nums,target,0,nums.size()-1);
    }
};