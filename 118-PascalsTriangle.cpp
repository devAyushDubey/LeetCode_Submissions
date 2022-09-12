class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec = {};
        if(numRows>=1)
            vec.push_back({1});
        if(numRows>=2){
            vec.push_back({1,1});
            
            for(int i =3;i<=numRows;i++){
                vector<int> t;
                t.push_back(1);
                for(int j = 1;j<i-1;j++){
                    vector<int> temp = vec[i-2];
                    t.push_back(temp[j-1]+temp[j]);
                }
                t.push_back(1);
                vec.push_back(t);
            }
        }
        return    
    }
};