class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        
        for(int i =n-1;i>=0;i--){
            int cur = matrix[i][0];
            int it = i+1;
            int j=1;
            while(it<n && it>=0 && j>=0 && j<m){
                if(matrix[it][j] != cur)
                    return false;
                it++;
                j++;
            }
            
        }
        for(int i =0;i<m;i++){
            int cur = matrix[0][i];
            int it = i+1;
            int j=1;
            while(it<m && it>=0 && j>=0 && j<n){
                if(matrix[j][it] != cur)
                    return false;
                it++;
                j++;
            }
            
        }
        
        return true;
    }
};