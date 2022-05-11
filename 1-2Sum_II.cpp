class Solution
{
    
    public:
    vector<int> twoSum(vector<int> num, int target){
        int i=0,t=0,nm=0;
        vector<int> temp;
        int n = num.size();
        
        map<int,int> dmap;
        
        while(i<n){
            nm = num[i];
            int diff = target - nm;
            t = dmap[diff];
            //cout<<diff<<endl;    
            if(t != 0){
                temp.push_back(t-1);
                temp.push_back(i);
                return temp;
            }
            dmap[nm] = i+1;
            i++;
        }
        return temp;
    }
};