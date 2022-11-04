class Solution {
public:
    
    vector<vector<int>> ans;
    
    void comb(int r,int cur,int k,int sum, int target,vector<int> combinations){
        
        // cout<<r<<" "<<cur<<" "<<sum<<" "<<k<<endl;
        // for(auto it: combinations)
        //     cout<<it<<" ";
        // cout<<endl<<endl;
        if(sum > target || r>k)
            return;
        
        if(r==k){
            if(sum == target){
                ans.push_back(combinations);
            }
            return;
        }
        
        
        for(int i = cur;i<=9;i++){
            combinations.push_back(i);
            sum += i;
            comb(r+1,i+1,k,sum,target,combinations);
            if(sum >= target)
                return;
            combinations.pop_back();
            sum -= i;
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        
        vector<int> temp = {};
        comb(0,1,k,0,n,temp);
        
        return ans;
        
    }
};