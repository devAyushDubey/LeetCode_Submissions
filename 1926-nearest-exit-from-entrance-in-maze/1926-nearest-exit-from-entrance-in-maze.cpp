class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {      int n=maze.size(),m=maze[0].size();
       queue<pair<int,int>>q;
       q.push({entrance[0],entrance[1]});
       maze[entrance[0]][entrance[1]]='+';
       int res=0;
       vector<int>r= {-1, 1, 0, 0};
       vector<int>c= {0, 0, -1, 1};
       while(q.size()>0)
       {
           int size=q.size();
           while(size--)
           {
               int a=q.front().first,b=q.front().second,i,j;
               q.pop();
               for(int k=0;k<4;k++)
               {
                   i=a+r[k],j=b+c[k];
                   if(i<0||i>=n||j<0||j>=m||maze[i][j]=='+')
                   continue;
                   else
                   {   
                       maze[i][j]='+';
                       if(i==0||i==n-1||j==0||j==m-1)
                       return res+1;
                       else{
                           q.push({i,j});
                       }
                   }
               }
           }
           res++;
       }
        return -1;
    }
};