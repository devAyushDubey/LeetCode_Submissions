class Solution {
public:

    int bfs(int target,vector<int>&vec){
        int n = vec.size();
        vector<int>level(n,INT_MAX);
        queue<int>q;
        q.push(1);
        level[1]=0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i=1;i<=6;i++){
                if(u+i<n){
                    int k = vec[u+i];
                    if(k==-1){
                        if(level[u+i]>level[u]+1){
                            level[u+i]=level[u]+1;
                            q.push(u+i);
                        }
                    }
                    else if(level[k]>level[u]+1){
                        q.push(k);
                        level[k]=level[u]+1;
                    }
                }
            }
        }
        
        return level[target]==INT_MAX? -1:level[target];
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int>vec(n*n+10,n*n);
        int k = 1;
        bool flip = true;
        for(int i=n-1;i>=0;i--){
            if(flip){
                for(int j=0;j<n;j++){
                    vec[k++]=board[i][j];
                }
            }
            else{
                for(int j=n-1;j>=0;j--){
                    vec[k++]=board[i][j];
                }
            }
            flip^=1;
        }

        return bfs(n*n,vec);
    }
};