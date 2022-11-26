class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> stac;
        stac.push_back({nums[0],0});
        vector<int> ans (n,-1);
        
        for(int k =1;k<2*n;k++){
            int i = k%n;
            //cout<<i<<endl;
            if(nums[i] > stac.back()[0]){
                
                while(stac.size() > 0 && nums[i] > stac.back()[0]){
                    ans[stac.back()[1]] = nums[i];
                    stac.pop_back();
                }
                
                stac.push_back({nums[i],i});

            }
            else
                stac.push_back({nums[i],i});
            
        }
        
        // if(stac.size()){
        //     int m = stac.size()-1;
        //     while(m > 0){
        //         ans[stac.back()[1]] = stac[m-1][0];
        //         stac.pop_back();
        //         m--;
        //     }
        // }
        
        return ans;
        
    }
};