class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        int k = nums[0];
        int i =0;
        while(i<n){
            cout<<"Called: "<<i<<endl;
            k = nums[i];
            i++;
            while(i<n){
                if(nums[i]==k){
                    cout<<i<<" "<<nums[i]<<" "<<n<<endl;
                    cout<<endl;
                    nums.erase(nums.begin()+i);
                    n = nums.size();
                }else
                    break;
                
            }
           
        }
        cout<<i<<" "<<nums.size()<<endl;
        return nums.size();
    }
};