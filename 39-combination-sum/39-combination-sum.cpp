class Solution {
public:
    
    vector<vector<int>> ans;
    
    void generateSum(vector<int> vec,vector<int> combination, int n,int r,int sum,int target){
        
        if(sum>=target){
            if(sum==target)
                ans.push_back(combination);
            return;
        }
        
        for(int i=r;i<n;i++){
            sum = sum + vec[i];
            combination.push_back(vec[i]);
            generateSum(vec,combination,n,i,sum,target);
            combination.pop_back();
            sum = sum - vec[i];
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> comb;
        generateSum(candidates,comb,candidates.size(),0,0,target);
        
        return ans;
    }
};