class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int posInd=0, negInd=0;
        vector<int> arr;
        
        while(posInd<nums.size() && nums[posInd]<0) posInd++;
        while(negInd<nums.size() && nums[negInd]>0) negInd++;
        
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                arr.push_back(nums[posInd++]);
                while(posInd<nums.size() && nums[posInd]<0) posInd++;
            }
            else{
                arr.push_back(nums[negInd++]);
                while(negInd<nums.size() && nums[negInd]>0) negInd++;
            }
        }
        
        return arr;
    }
};