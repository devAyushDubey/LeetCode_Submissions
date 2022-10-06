class Solution {
public:
    
    int bSearch(vector<int>& nums, int l, int r){
        
        if(l<=r){
            int mid = l + (r-l)/2;
            if(mid!=0 && mid!=nums.size()-1){
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                    return mid;
                else if(nums[mid-1] > nums[mid])
                    return bSearch(nums,l,mid-1);
                else
                    return bSearch(nums,mid+1,r);
            }
            else{
                if(mid == 0){
                    if(nums[mid] > nums[mid+1])
                        return mid;
                    else
                        return 1;
                }
                else{
                    if(nums[mid] > nums[mid-1])
                        return mid;
                    else
                        return mid-1;
                }
            }
            
        }
        return -1;
    }
    
    
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        
        
        return bSearch(nums,0,nums.size()-1);
    }
};