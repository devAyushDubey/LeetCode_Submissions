class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string,int> rev;
        unordered_map<string,int> si_cnt;
        int pr=0,si=0;
        for(auto it: words){
            
            if(it[0] == it[1]){
                if(si_cnt[it]){
                    si_cnt.erase(it);
                    si--;
                    pr++;
                }
                else{
                    si_cnt[it]++;
                    si++;
                }
            }
            else if(rev[it]){
                rev[it]--;
                pr++;
            }
            else{
                reverse(it.begin(),it.end());
                rev[it]++;
            }
        }
        cout<<si<<" "<<pr<<endl;
        if(si)
            return 2*(2*pr+1);
        return 4*pr;
        
        
    }
};