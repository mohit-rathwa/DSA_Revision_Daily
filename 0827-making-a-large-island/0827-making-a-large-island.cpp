class disjointset{
    public:
    vector<int> rank,parent,size;
    disjointset(int n){
        rank.resize(n,0);
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findUparent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUparent(parent[node]);
    }
    void unionbysize(int u ,int v){
        int pv = findUparent(v);
        int pu = findUparent(u);
        if(pv == pu) return;
        if( size[pu] < size[pv] ){
            parent[pu] = pv;
            size[pv]+= size[pu];
        }else{
            parent[pv] = pu;
            size[pu]+= size[pv];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjointset ds(n*n);
        int area = 0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0) continue;
                for(int d=0;d<4;d++){
                    int nrow = dr[d] + i;
                    int ncol = dc[d] + j;
                    if(nrow>=0 && nrow<n && 
                    ncol>=0 && ncol<n && grid[nrow][ncol]){
                        int nodeno = i*n + j ;
                        int adjnode = nrow*n + ncol;
                        ds.unionbysize(nodeno , adjnode);
                    }
                }
            }
        }
        int mx=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) continue;
                set<int> st;
                for(int d=0;d<4;d++){
                    int nrow = i + dr[d];
                    int ncol = j + dc[d];
                    if(nrow >= 0 && nrow<n &&
                    ncol >= 0 && ncol<n &&
                    grid[nrow][ncol] == 1 ){
                        st.insert( ds.findUparent(nrow*n + ncol));
                    }
                }
                int tsize = 0;
                for(auto it : st){
                    tsize += ds.size[it];
                }
                mx = max(mx,tsize+1);
            }
        }

        for(int i=0;i<n*n;i++){
            mx = max(mx,ds.size[ds.findUparent(i)]);
        }

        return mx;
    }
};