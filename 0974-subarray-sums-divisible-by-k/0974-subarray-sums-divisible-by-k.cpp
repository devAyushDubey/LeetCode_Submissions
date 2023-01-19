class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int sum = 0,count = 0;
        unordered_map<int,int> freq;
        freq[0]++;
        for(auto it:nums){
            
            int rem = 0;
            sum+=it;
            
            if((sum%k)<0)
                rem = (sum%k)+k;
            else
                rem = sum%k;
            
            count += freq[rem];
            freq[rem]++;
        }
        return count;
    }
};