class Solution {
public:
    vector<vector<int>> ans;
    
    vector<int> copy(vector<int> nums, int num){
        nums.erase(find(nums.begin(),nums.end(),num));
        return nums;
    }
    
    void generatePermutations(vector<int> nums,vector<int> perm,int n,int freq[]){
        
        if(perm.size()==n){
            ans.push_back(perm);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(!freq[i]){
                perm.push_back(nums[i]);
                freq[i] = 1;
                generatePermutations(nums,perm,n,freq);
                freq[i] = 0;
                perm.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> perm;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++) freq[i]=0;
        generatePermutations(nums,perm,nums.size(),freq);
        
        return ans;
    }
};