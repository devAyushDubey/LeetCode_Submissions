class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;
        
        
        map<int,bool> mp;
        map<int,bool> temp;
        
        for(int i =0;i<nums.size();i++)
            mp[nums[i]] = true;
        
        temp = mp;
        
        for(auto &it: mp){
            //cout<<(it.first)-1<<" ";
            if(temp[(it.first)-1])
                it.second = false;
        }
        //cout<<endl;
        int count,mcount=0;
        for(auto &it: mp){
            if(it.second){
                int i = it.first + 1;
                count = 1;
                while(temp[i++]) count++;
                if(mcount<count)
                    mcount = count;
            }
            //cout<<it.second<<" ";
        }
        
        return mcount;
    }
};