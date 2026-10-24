class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dcol[4] = {-1,1,0,0};
        int drow[4] = {0,0,-1,1};
        int cnt = 0;

        while(true){
            bool change = false;
            vector<vector<int>> next = grid;

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j] == 2){
                        for(int k=0;k<4;k++){
                            int idx = i + drow[k];
                            int jdx = j + dcol[k];
                            if(idx>=0 && idx<n && jdx>=0 && jdx<m && grid[idx][jdx]==1){
                                next[idx][jdx] = 2;
                                change = true;
                            }
                        }
                    }
                }
            }
            if(!change) break;
            grid = next;
            cnt++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return cnt;
    }
};