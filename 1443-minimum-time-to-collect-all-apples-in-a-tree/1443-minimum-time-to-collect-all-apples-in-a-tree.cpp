class Solution {
public:
    int helper(vector<int> graph[], int i, vector<bool> &apple, vector<bool> &visit){
        visit[i] = true;
        int res = 0;
        for(auto a : graph[i]){
            if(!visit[a]){
                res += helper(graph, a, apple, visit);
            }
        }
        if(i!=0 && (res > 0 || apple[i])){
            res += 1;
        }
        return res;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> graph[n];
        for(auto a : edges){
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        vector<bool> visit(n, false);
        int res = helper(graph, 0, hasApple, visit);
        return res*2;
    }
};