class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        if(columnCheck(board) && rowCheck(board) && boxCheck(board))
            return true;
        return false;
    }
    
    bool columnCheck(vector<vector<char>> &board){
        
        set<char> st;
        
        for(int i = 0;i<9;i++){
            st.clear();
            for(int j = 0;j<9;j++){
                if(board[i][j]!='.'){
                    if(st.find(board[i][j]) != st.end()){
                        cout<<board[i][j]<<endl;
                        return false;
                    }
                    st.insert(board[i][j]);
                }
            }
        }
        return true;
    }
    bool rowCheck(vector<vector<char>> &board){
        
        set<char> st;
        
        for(int i = 0;i<9;i++){
            st.clear();
            for(int j = 0;j<9;j++){
                if(board[j][i]!='.'){
                    if(st.find(board[j][i]) != st.end()){
                        cout<<board[j][i]<<endl;
                        return false;
                    }
                    st.insert(board[j][i]);
                }
            }
        }
        return true;
    }
    bool boxCheck(vector<vector<char>> &board){
        
        set<char> st;
        
        for(int i =0;i<9;i += 3){
            for(int j=0;j<9;j+=3){
                st.clear();
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(board[k][l]!='.'){
                            if(st.find(board[k][l]) != st.end()){
                                cout<<board[k][l]<<endl;
                                return false;
                            }
                            st.insert(board[k][l]);
                        }
                    }
                }
            }
        }
        
        return true;
    }
};