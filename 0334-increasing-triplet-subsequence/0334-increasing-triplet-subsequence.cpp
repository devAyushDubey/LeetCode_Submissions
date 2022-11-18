class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        multimap<int,int> mp;
        
        for(int i =0;i<n;i++)
            mp.insert({nums[i],i});
        
        multimap<int,int> :: iterator it = mp.begin();
        while(it!=mp.end()){
            
            int key = it->first;
            int index = it->second;
            int c = 1;
            //cout<<key<<" "<<index<<endl;
            multimap<int,int> :: iterator jt;
            int m = index;
            int k = key;
            //cout<<endl;
            for(jt = it;jt!=mp.end();jt++){
                //cout<<jt->second<<" "<<index<<endl;
                if(jt->first > k && jt->second > m){
                    //cout<<" | "<<jt->second<<" "<<m<<endl;
                    m = jt->second;
                    k = jt->first;
                    c++;
                }
                
                if(c>=3)
                    return true;
            }
            
            while(it!= mp.end() && it->first == key)
                it++;
            //cout<<endl;
        }
        
        return false;
    }
};