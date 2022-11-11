class Solution {
public:
    
    void findComb(string dig,vector<string>& comb,unordered_map<char,string> &data){
        
        //cout<<dig<<endl;
        
        if(dig.length()==0)
            return;
        
        char num = dig[0];
        dig = dig.substr(1);
        
        
        string val = data[num];
        
        vector<string> temp;
        for(string it: comb){
            for(char jt: val){
                //cout<<jt<<" ";
                temp.push_back(it+jt);
            }
            //cout<<endl;
        }
        comb = temp;
        findComb(dig,comb,data);
    }
    
    
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        vector<string> ans;
        
        if(digits.length() == 0)
            return ans;
        
        ans = {""};
        
        findComb(digits,ans,mp);
        
        return ans;
    }
};