class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> preProd;
        vector<int> postProd;
        
        int prod = 1;
        preProd.push_back(prod);
        
        for(int i = 0;i<n-1;i++){
            prod *= nums[i];
            preProd.push_back(prod);
        }
        
        prod = 1;
        postProd.push_back(prod);
        
        for(int i = n-1;i>0;i--){
            prod *= nums[i];
            postProd.push_back(prod);
        }
        
        reverse(postProd.begin(),postProd.end());
        
        
        for(int i=0;i<n;i++)
            nums[i] = preProd[i] * postProd[i];
        
        return nums;
        
    }
    
};