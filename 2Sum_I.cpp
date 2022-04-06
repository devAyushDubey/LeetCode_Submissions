class Solution
{
    
    public:
    vector<int> twoSum(vector<int> num, int target){
        vector<int> temp = num;
        int n = num.size();
        sort(num.begin(), num.end());
        int low=0,high=n-1;
    
        int currsum = num[low] + num[high];
        while(currsum != target){
            while(currsum>target){
                high--;
                currsum = num[low] + num[high];
            }
            while(currsum<target){
                low++;
                currsum = num[low] + num[high];
            }
        }
        vector<int> :: iterator it = find(temp.begin(),temp.end(),num[low]);
        int l = it-temp.begin();
        vector<int> la = {num[high]};
        vector<int> :: iterator itt = find_end(temp.begin(),temp.end(),la.begin(),la.end());
        int r = itt-temp.begin();
        vector<int> ans = {l,r};
        return ans;   
    }
    
};