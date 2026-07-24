class Solution {
public:
    bool check(vector<vector<char>>& board,int i ,int j){
        for(int p=0;p<board[0].size();p++){
            if(board[i][p]==board[i][j]&&p!=j){
                return false;
            }
        }
        for(int p=0;p<board.size();p++){
            if(board[p][j]==board[i][j]&&p!=i){
                return false;
            }
        }
        int n = (i/3)*3;
        int m = (j/3)*3;
            for(int p=n;p<n+3;p++){
                for(int q=m;q<m+3;q++){
                    if(board[p][q]==board[i][j] && (p!=i || q!=j)){
                        return false;
                    }
                }
            }
        
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    continue;
                }
                else{
                    bool flag  = check(board,i,j);
                    if(flag==false){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};