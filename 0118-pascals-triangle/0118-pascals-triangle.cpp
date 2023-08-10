class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        if(numRows == 1) return {{1}};
        else if(numRows == 2) return {{1},{1,1}};
        else return providePascal(numRows);
    }
    
    vector<vector<int>> providePascal(int row) {
        
        vector<vector<int>> triangle = {{1},{1,1}};
        
        for(int i = 2; i < row; i++){
            
            vector<int> temp = {1};
            
            for(int j = 1; j < i; j++) temp.push_back(triangle[i-1][j-1] + triangle[i-1][j]);
            
            temp.push_back(1);
            
            triangle.push_back(temp);
        }
        
        return triangle;
    }
};

    