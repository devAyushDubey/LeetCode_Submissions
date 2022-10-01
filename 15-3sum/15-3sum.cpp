class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            
            if(i>0 && nums[i] == nums[i-1])
                continue;
            
            int l = i+1, r=nums.size()-1;
            
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0){
                    int a = r;
                    while(a>=0 && nums[a] == nums[r])
                        a--;
                    r = a;
                }
                else if(sum < 0){
                    int a = l;
                    while(a<nums.size() && nums[a] == nums[l])
                        a++;
                    l = a;
                }
                if(sum == 0){
                    vector<int> temp = {nums[i],nums[l],nums[r]};
                    ans.push_back(temp);
                    int a = r;
                    while(a>=0 && nums[a] == nums[r])
                        a--;
                    r = a;
                    a = l;
                    while(a<nums.size() && nums[a] == nums[l])
                        a++;
                    l = a;
                }
                
            }
        }
        
        return ans;
    }
};