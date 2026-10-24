class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<tuple<int,int,int>> que;
        int cnt =0 ;
        int drow[4] = {-1,1,0,0};
        int dcol[4] = {0,0,1,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    que.push({i,j,0});
                }
                else if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        int time = 0;
        while(!que.empty()){
            auto [x,y,t] = que.front();
            que.pop();

            time = max(time , t);
            for(int k=0;k<4;k++){
                int idx = x + drow[k];
                int jdx = y + dcol[k];

                if(idx>=0 && idx<n && jdx>=0 && jdx<m && grid[idx][jdx]==1){
                    grid[idx][jdx] = 2;
                    que.push({idx,jdx,t+1});
                    cnt--;
                }
            }
        }

        if(cnt == 0 ) return time;
        return -1;
        
    }
};