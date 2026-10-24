class Disjointset{
    private:
    vector<int> par,rank;
    public:
    Disjointset(int n){
        rank.resize(n,0);
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }
    int findUpar(int node){
        if(par[node]==node){
            return node;
        }
        return par[node]=findUpar(par[node]);
    }
    void unionbyrank(int u ,int v){
        int ult_u = findUpar(u);
        int ult_v = findUpar(v);

        if(ult_u == ult_v) return;
        if(rank[ult_v] < rank[ult_u]){
            par[ult_v] = ult_u;
        }
        else if(rank[ult_u] < rank[ult_v]){
            par[ult_u] = ult_v;
        }
        else{
            par[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        Disjointset ds(n);

        for(int u=0;u<graph.size();u++){
            for(auto v : graph[u]){

                if(ds.findUpar(u)==ds.findUpar(v)){
                    return false;
                }
                else{
                    ds.unionbyrank(graph[u][0] , v);
                }
            }
        }
        return true;
    }
};