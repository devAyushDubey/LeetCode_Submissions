class Solution {
public:
    
    
    vector<int> findBall(vector<vector<int>>& grid) {
        
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> ans (m,-1);
        int j,l;
        for(int i=0;i<m;i++){
            j=0;
            l=i;
            while(j<n){
                //cout<<l<<" "<<j<<" ";
                if(l<m-1 && grid[j][l] == 1 && grid[j][l+1] == 1){
                    cout<<grid[j][l]<<" "<<grid[j][l+1];
                    l++;
                }
                else if(l>0 && grid[j][l] == -1 && grid[j][l-1] == -1){
                    //cout<<grid[j][l]<<" "<<grid[j][l-1];
                    l--;
                }
                else{
                    l++;
                    break;
                }
                //cout<<endl;
                j++;
            }
            //cout<<endl;
            if(j==n){
                ans[i] = l;
            } 
        }
        
        return ans;
    }
};