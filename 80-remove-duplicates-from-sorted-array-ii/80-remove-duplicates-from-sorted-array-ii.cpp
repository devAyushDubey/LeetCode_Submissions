class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int cur = nums[0];
        int count = 0;
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i] == cur){
                count++;
            }
            if(count>2){
                nums.erase(nums.begin() + i);
                count--;
                i--;
                continue;
            }
            if(nums[i] != cur){
                cur = nums[i];
                count=1;
            }
            
        }
        
        return nums.size();
    }
};