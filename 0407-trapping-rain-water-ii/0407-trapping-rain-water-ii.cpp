class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();

        if(n==0) return 0;
        if(n<3 || m<3) return 0;

        priority_queue<tuple<int,int,int> ,vector<tuple<int,int,int>> ,greater<tuple<int,int,int>>> pq;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    pq.push({heightMap[i][j] , i, j});
                    vis[i][j] = 1;
                }
            }
        }
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        int water = 0;
        int max_wall =0;

        while(!pq.empty()){
            auto [dis , u , v] = pq.top();
            pq.pop();

            max_wall = max(max_wall,dis);

            for(int i=0;i<4;i++){
                int dr = u + drow[i];
                int dc = v + dcol[i];
                if(dr>=0 && dr<n && dc>=0 && dc<m){
                    if(!vis[dr][dc]){
                        if(max_wall > heightMap[dr][dc]){
                            water += max_wall - heightMap[dr][dc];
                        }
                        vis[dr][dc]=1;

                        pq.push({heightMap[dr][dc],dr,dc});
                    }
                }
            }
        }
        return water;
    }
};