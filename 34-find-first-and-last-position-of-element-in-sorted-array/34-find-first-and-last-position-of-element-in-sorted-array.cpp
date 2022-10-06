class Solution {
public:
    
    vector<int> ans = vector<int>(2,-1);
    
    void bSearch(vector<int> nums,int target, int l, int r){
        
        if(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] < target)
                bSearch(nums,target,mid+1,r);
            else if(nums[mid] > target)
                bSearch(nums,target,l,mid-1);
            else{
                //cout<<mid<<endl;
                if(ans[0]==-1 && ans[1] == -1){
                    ans[0] = mid;
                    ans[1] = mid;
                }    
                else{
                    if(ans[0] > mid)
                        ans[0] = mid;
                    else if(ans[1] < mid)
                        ans[1] = mid;
                }
                //cout<<ans[0]<<" "<<ans[1]<<endl;
                bSearch(nums,target,mid+1,r);
                bSearch(nums,target,l,mid-1);
                
            }
        }
        
        return;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        bSearch(nums,target,0,nums.size()-1); 
        return ans;
    }
};