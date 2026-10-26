class Solution {
public:
    int dfs(int nd ,vector<int>&vis,vector<int>&pathvis ,vector<vector<int>>&adj,stack<int>&st){
        vis[nd] = 1;
        pathvis[nd] = 1;

        for(auto it : adj[nd]){
            if(!vis[it]){
                if(dfs(it ,vis , pathvis , adj, st)){
                    return true;
                }
            }
            else if(pathvis[it]){
                return true;
            }
        }

        pathvis[nd] = 0;
        st.push(nd);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<vector<int>> adj(n);
        stack<int> st;

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
    

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i ,vis , pathvis , adj , st)){
                    return {};
                }
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};