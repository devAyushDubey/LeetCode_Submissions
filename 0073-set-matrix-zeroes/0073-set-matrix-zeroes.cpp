class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<vector<int>> cords;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(!matrix[i][j]) cords.push_back({i,j});
            }
        }
        
        for(auto it : cords) makeZeroes(matrix,it[0],it[1]);
    }
    
    void makeZeroes(vector<vector<int>>& matrix, int row, int col) {
        
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < m; i++) matrix[i][col] = 0;
        for(int i = 0; i < n; i++) matrix[row][i] = 0;
    }
};