class Solution {
public:
    bool isvalid(int r,int c, char ch,vector<vector<char>>&board){

        for(int i=0;i<9;i++){
            if(board[r][i] == ch) return false;
            if(board[i][c] == ch) return false;
        }

        int i_ = r/3 * 3;
        int j_ = c/3 * 3;

        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                if(board[i_+x][j_+y] == ch) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n = board.size();

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char ch = '1';ch<='9';ch++){
                        if(isvalid(i,j,ch ,board)){
                            board[i][j] = ch;
                            if(solve(board))return true;
                            board[i][j] = '.';
                        } 
                    }
                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};