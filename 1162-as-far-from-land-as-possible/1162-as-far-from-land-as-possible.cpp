class Solution {
public:
    
    bool isValid(int i, int j, int n){
        
        if(i==n || j==n || j<0 || i<0)
            return false;
        return true;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        
        vector<int> dr = {0,1,0,-1};
        vector<int> dc = {1,0,-1,0};
        
        int n = grid.size();
        vector<vector<int>> dist (n, vector<int> (n, -1));
        queue<vector<int>> q;
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            
            vector<int> cur = q.front();
            q.pop();
            
            if(grid[cur[0]][cur[1]] == 0){
                ans = max(ans,dist[cur[0]][cur[1]]);
            }
            
            for(int i=0;i<4;i++){
                
                int x = cur[0] + dr[i];
                int y = cur[1] + dc[i];
                
                if( isValid(x,y,n) && dist[x][y] == -1){
                    dist[x][y] = dist[cur[0]][cur[1]] + 1;
                    q.push({x,y});
                }
            }
            
        }
        
        
        return ans==0?-1:ans;
    }
};