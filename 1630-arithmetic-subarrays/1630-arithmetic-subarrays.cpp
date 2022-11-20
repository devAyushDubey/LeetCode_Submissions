class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int n = nums.size();
        int m = l.size();
        
        vector<bool> ans (m,false);
        
        for(int i=0;i<m;i++){
            
            bool flag = false;
            int il = l[i];
            int ir = r[i];
            int len = ir-il;
            vector<int> temp;
            
            for(int j=il;j<=ir;j++)
                temp.push_back(nums[j]);
            
                
            sort(temp.begin(),temp.end());
            
            int dif = temp[1] - temp[0];
            
            for(int j=1;j<len;j++){
                if((temp[j+1] - temp[j]) != dif){
                    flag = true;
                    break;
                }
            }
            
            if(flag)
                continue;
            
            ans[i] = true;
            
        }
        
        return ans;
    }
};