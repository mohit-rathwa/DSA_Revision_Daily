class Solution {
public:
    int drow[8]={-1,1,0,0,1,1,-1,-1};
    int dcol[8]={0,0,-1,1,-1,1,1,-1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] || grid[n-1][n-1]){
            return -1;
        }

        queue<tuple<int,int,int>> que;
        que.push({1,0,0});
        vector<vector<int>> dis(n , vector<int> (n , 1e9));
        dis[0][0]=1;

        while(!que.empty()){
            auto [d,r,c] = que.front();
            que.pop();

            if(r==n-1 && c==n-1) return dis[r][c];

            //if(grid[r][c]) break;

            for(int k=0;k<8;k++){
                int dr = r + drow[k];
                int dc = c + dcol[k];

                if(dr>=0 && dr<n && dc>=0 && dc<n && !grid[dr][dc]){
                    if(dis[r][c]+1<dis[dr][dc]){
                        dis[dr][dc] = dis[r][c]+1;
                        que.push({dis[dr][dc] ,dr,dc});
                    }
                }
            }
        }

        return -1;

    }
};