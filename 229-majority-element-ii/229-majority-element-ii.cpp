class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int el1=-1,el2=-1,c1=0,c2=0;
        
        int l = nums.size()/3;
        
        for(auto &it: nums){
            
            if(it == el1) c1++;
            else if(it == el2) c2++;
            else if(c1 == 0){
                el1 = it;
                c1 = 1;
            }
            else if(c2==0){
                el2 = it;
                c2 = 1;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        c1=0;
        c2=0;
        for(auto it: nums){
            if(it == el1)
                c1++;
            else if(it==el2)
                c2++;
        }
        
        nums.clear();
        
        if(c1>l)
            nums.push_back(el1);
        if(c2>l)
            nums.push_back(el2);
        
        return nums;
            
    }
};