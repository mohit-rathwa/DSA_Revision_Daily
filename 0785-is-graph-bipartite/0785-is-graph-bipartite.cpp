class Solution {
public:
    bool dfs(int u,int clr , vector<vector<int>>&graph ,vector<int>&clrs){
        int n = clrs.size();

        clrs[u] = clr;

        for(auto v :graph[u]){
            if(clrs[v] == -1){
                if(!dfs( v , !clr , graph , clrs)){
                    return false;
                }
            }
            else if(clrs[u]==clrs[v]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> clrs(n,-1);

        for(int u=0 ; u<n ; u++){
            if(clrs[u]==-1){
            if(!dfs(u , 0 , graph , clrs)){
                return false;
            }
        }
        }
        return true;
    }
};