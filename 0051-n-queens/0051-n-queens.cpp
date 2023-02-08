class Solution {
public:
    
    vector<vector<string>> ans;
    
    bool isBoxSafe(vector<string> &vec_str, int &x,int &y){
        
        int l = vec_str.size();
        
        int i=x,j=y;
        while(i<l && j<l && i>=0 && j>=0){
            if(vec_str[i][j] == 'Q')
                return false;
            i--;
        }
        i=x;
        while(i<l && j<l && i>=0 && j>=0){
            if(vec_str[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        i=x;
        j=y;
        while(i<l && j<l && i>=0 && j>=0){
            if(vec_str[i][j] == 'Q')
                return false;
            i--;
            j++;
        }
        
        return true;
    }
    
    void nQueens(vector<string> &vec, int &n, int r){
        
        if(r==n){
            ans.push_back(vec);
            return;
        }
        
        
        for(int i=0;i<n;i++){
            if(isBoxSafe(vec, r,i)){
                vec[r][i] = 'Q';
                nQueens(vec,n,r+1);
                vec[r][i] = '.';
            }
        }
        
    }
    
        
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> row;
        string st;
        
        for(int i=0;i<n;i++)
            st = st + ".";
        
        for(int i=0;i<n;i++)
            row.push_back(st);
        
        
        nQueens(row,n,0);
        
        return ans;
            
        
    }
};