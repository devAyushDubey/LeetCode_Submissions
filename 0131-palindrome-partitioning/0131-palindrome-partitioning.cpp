class Solution {
public:
    
    vector<vector<string>> ans;
    
    bool isPalindrome(string st){
        //cout<<st<<endl;
        
        vector<char> vec;
        int n = st.length();
        
        int l =0;
        int r = n-1;
        while(l<r){
            if(st[l] != st[r])
                return false;
            l++;
            r--;
        }
        return true;
        
    }
    
    void perm(string s,vector<string> gy){
        //cout<<s<<endl;
        if(s.length()==0){
            for(auto it: gy){
                if(!isPalindrome(it))
                    return;
            }
            ans.push_back(gy);
            return;
        }
        
        string temp = "";
        temp += s[0];
        
        gy.push_back(temp);
        perm(s.substr(1),gy);
        gy.pop_back();
        
        if(gy.size()>0){
            string sx = gy.back();
            // for(auto it: gy){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            sx += temp;
            //cout<<"SX "<<sx<<endl;
            gy[gy.size()-1] = sx;
            perm(s.substr(1),gy);
            gy.pop_back();
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> temp = {};
        perm(s,temp);
        
        return ans;
    }
};