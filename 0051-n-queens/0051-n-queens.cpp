class Solution {
public:
    void solve(int r,vector<bool>&col , vector<bool>&diag1 , vector<bool>&diag2 
    ,vector<string>&board,vector<vector<string>>&ans){

        int n = col.size();
        if(r == n){
            ans.push_back(board);
            return;
        }

       for(int c=0;c<n;c++){
            int d1 = r+c;
            int d2 = r-c+n-1;

            if(!col[c] && !diag1[d1] && !diag2[d2]){

                col[c] = diag1[d1] = diag2[d2] = true;
                board[r][c] = 'Q';
                solve(r+1 , col , diag1,diag2 , board , ans);
                col[c] = diag1[d1] = diag2[d2] = false;
                board[r][c] = '.';

            }
       }
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n , string(n , '.'));
        vector<vector<string>> ans;

        vector<bool> col(n,false);
        vector<bool> diag1(2*n-1 , false);
        vector<bool> diag2(2*n-1 , false);

        solve(0 ,col,diag1,diag2,board,ans);

        return ans;
    }
};