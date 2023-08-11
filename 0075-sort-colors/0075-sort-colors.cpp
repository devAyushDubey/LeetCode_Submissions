class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0,white=0,blue=0;
        for(int i=0;i<nums.size();i++){
            switch(nums[i]){
                case 0:
                    red++;
                    break;
                case 1:
                    white++;
                    break;
                case 2:
                    blue++;
                    break;
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(red?red--:red) nums[i]=0;
            else if(white?white--:white) nums[i]=1;
            else nums[i]=2;
        }
    }
};