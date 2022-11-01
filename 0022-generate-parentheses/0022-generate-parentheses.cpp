class Solution {
public:
    
    vector<string> ans;
    
    void para(int right, int left, int open,string st){
        //cout<<right<<" "<<left<<" "<<open<<" "<<st<<endl;
        if(right == 0 && left == 0 && open==0){
            ans.push_back(st);
            return;
        }
        
        if(right>0){
            para(right-1,left,open+1,st + "(");
        }
        //cout<<right<<" "<<left<<" "<<open<<endl;
        if(open!=0){
            para(right,left-1,open-1,st+")");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        para(n-1,n,1,"(");
        return ans;
    }
};