class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=0,minn = INT_MAX,ind=0,j=0;
        
        while(i < strs.size()){
            if(strs[i].length()<minn){
                minn = strs[i].length();
                ind = i;
            }
            i++;
        }
        //cout<<minn<<endl;
        i=0;
        //char ct = strs[ind][0];
        string st ="";
        while(i < minn){
            char ct = strs[ind][i];
            for(j=0;j<strs.size();j++){
                if(strs[j][i] != ct)
                    break;   
            }
            if(j!=strs.size())
                break;
            i++;
        }
        
        st = strs[ind].substr(0,i);
        return st;
    }
};