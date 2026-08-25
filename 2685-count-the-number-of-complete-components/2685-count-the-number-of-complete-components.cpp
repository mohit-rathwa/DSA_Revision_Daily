class DisjointSet{
    public:
    vector<int> par,size,edg;
    DisjointSet(int n){
        par.resize(n,0);
        size.resize(n,1);
        edg.resize(n,0);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }
    int FindUpar(int u){
        if( u == par[u]){
            return u;
        }
        return par[u] = FindUpar(par[u]);
    }
    void UnionBySize(int u,int v){
        int ult_u = FindUpar(u);
        int ult_v = FindUpar(v);

        if(ult_u == ult_v){
            edg[ult_u]++;
            return ;
        }
        if(size[ult_u] < size[ult_v]){
            par[ult_u] = ult_v;
            size[ult_v]+=size[ult_u];
            edg[ult_v] += 1 + edg[ult_u];
        } 
        else{
            par[ult_v] = ult_u;
            size[ult_u]+=size[ult_v];
            edg[ult_u] += 1 + edg[ult_v];
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(auto it : edges){
            ds.UnionBySize(it[0],it[1]);
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(ds.par[i] == i){
                int v = ds.size[i];
                int  n = ds.edg[i];
                if( n == (v*(v-1)/2) ){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};