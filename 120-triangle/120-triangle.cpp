class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        
        for(int i=1;i<n;i++){
            for(int j=0;j<triangle[i].size();j++){
                //cout<<i<<" "<<j<<endl;
                if(j == 0)
                    triangle[i][j] = triangle[i][j] + triangle[i-1][j];
                else if(j == triangle[i].size()-1)
                    triangle[i][j] = triangle[i][j] + triangle[i-1][triangle[i-1].size()-1];
                else
                    triangle[i][j] = triangle[i][j] + min(triangle[i-1][j-1],triangle[i-1][j]);
            }
        }
        
        for(auto it: triangle){
            for(auto jt: it)
                cout<<jt<<" ";
            cout<<endl;
        }
        
        return *min_element(triangle[n-1].begin(),triangle[n-1].end());
        
    }
};