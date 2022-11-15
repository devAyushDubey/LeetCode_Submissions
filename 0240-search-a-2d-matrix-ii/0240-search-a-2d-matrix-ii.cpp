class Solution {
public:
   
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
    for(const auto & x : matrix){
        for( int n : x){
            if(n == target)
                return true;
        }
    }
    
    return false;

    



}

};