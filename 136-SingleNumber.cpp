class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> :: iterator it = nums.begin();
        for(it = nums.begin();it<nums.end();it++){
            int c = count(nums.begin(),nums.end(),*it);
            if(c!=2)
                return *it;
        }
        
        return *it;
    }
};{\rtf1}