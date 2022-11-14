class Solution {
public:
    void dfs(int src,vector <int> adj[],vector <bool> &vis){

        vis[src]=true;

        for(int x: adj[src]){

            if(vis[x]==false){
                dfs(x,adj,vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();

        vector <int> adj[n];

        for(int i=0;i<n;i++){
            int u1=stones[i][0];
            int v1=stones[i][1];
            for(int j=i+1;j<n;j++){
                int u2=stones[j][0];
                int v2=stones[j][1];
                if(u1==u2 || v1==v2){

                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector <bool> vis(n,false);
        for(int i=0;i<n;i++){

            if(vis[i]==false){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return n-ans;
    }
};