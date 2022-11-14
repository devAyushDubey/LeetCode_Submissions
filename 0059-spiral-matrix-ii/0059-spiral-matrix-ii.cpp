class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int i=0,j=0,cnt=1;
        vector<vector<int>> vec (n, vector<int> (n,0));
        
        while(cnt<=(n*n)){
            
            for(i=j;i<n-j;i++){
                //cout<<j<<" "<<i<<"  ";
                vec[j][i] = cnt++;
            }
            //cout<<endl;
            if(cnt > n*n)
                break;
            
            for(i=j+1;i<n-j;i++){
                //cout<<i<<" "<<n-j-1<<"  ";
                vec[i][n-j-1] = cnt++;
            }
            //cout<<endl;
            if(cnt > n*n)
                break;
            //cout<<"J: "<<j<<endl;
            for(i=n-j-2;i>=j;i--){
                //cout<<n-j-1<<" "<<i<<"  ";
                vec[n-j-1][i] = cnt++;
            }
                
            //cout<<cnt<<endl;
            if(cnt > n*n)
                break;
            //cout<<endl;
            for(i=n-j-2;i>j;i--){
                //cout<<i<<" "<<j<<"  ";
                vec[i][j] = cnt++;
            }
            //cout<<endl;
            j++;
        }
        
        return vec;
        
    }
};