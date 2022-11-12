class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        if(nums.size()==0)
            return true;
        
        int n = nums.size();
        int k = nums[0];
        int h=0;
        while(h<n && nums[h]==k){
            h++;
        }
        if(h>=n){
            return true;
        }
        if(nums[0] > nums[h]){
            for(int i =h;i<n-1;i++){
                if(nums[i] < nums[i+1])
                    return false;
            }
        }
        else{
            for(int i =h;i<n-1;i++){
                if(nums[i] > nums[i+1])
                    return false;
            }
        }
        
        return true;
    }
};