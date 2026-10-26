class Disjointset{
    private:
    vector<int> par,rank;
    public:
    Disjointset(int n){
        rank.resize(n,0);
        par.resize(n,0);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }
    int findupar(int node){
        if(node == par[node]){
            return node;
        }
        return par[node] = findupar(par[node]);
    }
    void unionbyrank(int u ,int v){
        int ult_u = findupar(u);
        int ult_v = findupar(v);

        if(ult_u == ult_v) return;
        if(rank[ult_u] < rank[ult_v]){
            par[ult_u] = ult_v;
        }
        else if(rank[ult_u]>rank[ult_v]){
            par[ult_v] = ult_u;
        }
        else{
            par[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string , int> mp_str_nd;

        Disjointset ds(n);

        for(int i=0;i<n;i++){
            for(int j=1 ;j<accounts[i].size() ;j++){
                string mail = accounts[i][j];
                if(mp_str_nd.find(mail) == mp_str_nd.end()){
                    mp_str_nd[mail] = i;
                }
                else{
                    ds.unionbyrank(i , mp_str_nd[mail]);
                }
            }
        }

        vector<vector<string>> merged(n);

        for(auto it : mp_str_nd){
            int node = it.second;
            string mail = it.first;
            int par = ds.findupar(node);
            merged[par].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i=0;i<n;i++){
            if(merged[i].size()==0) continue;
            sort(merged[i].begin(),merged[i].end());

            vector<string> tmp;
            tmp.push_back(accounts[i][0]);
            for(auto it : merged[i]){
                tmp.push_back(it);
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};