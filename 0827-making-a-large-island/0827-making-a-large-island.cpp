class Disjointset{
    public:
    vector<int> size,par;
    Disjointset(int n){
        size.resize(n,1);
        par.resize(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    int findupar(int nd){
        if(nd == par[nd]){
            return nd;
        }
        return par[nd]=findupar(par[nd]);
    }

    void unionbysize(int u,int v){
        int ult_u = findupar(u);
        int ult_v = findupar(v);
        if(ult_u == ult_v) return;
        if(size[ult_u]<size[ult_v]){
            par[ult_u] = ult_v;
            size[ult_v]+=size[ult_u];
        }
        else{
            par[ult_v] = ult_u;
            size[ult_u]+=size[ult_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int drow[4] = {-1,0,0,1};
        int dcol[4] = {0,1,-1,0};

        Disjointset ds(n*n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)continue;

                for(int k=0;k<4;k++){
                    int dr = i+drow[k];
                    int dc = j+dcol[k];

                    if(dr>=0 && dr<n && dc>=0 && dc<n && grid[dr][dc]){
                        int nd = i*n + j;
                        int adj_nd = dr*n + dc;
                        ds.unionbysize(nd , adj_nd);
                    }
                }
            }
        }

        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]) continue;
                
                set<int> st;
                for(int k=0;k<4;k++){
                    int dr = drow[k]+i;
                    int dc = dcol[k]+j;

                    if(dr>=0 && dr<n && dc>=0 && dc<n && grid[dr][dc]){
                        st.insert(ds.findupar(dr*n+dc));
                    }
                }
                int t_sum = 0;
                for(auto it : st){
                    t_sum+=ds.size[it];
                }
                maxi = max(maxi , t_sum+1);
            }
        }

        if(maxi == 0) return n*n;

        return maxi;
    }
};