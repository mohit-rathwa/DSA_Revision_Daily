class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> inorder(n,0);
        vector<vector<int>> adj(n);
        queue<int> que;
        vector<int> ans;

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            inorder[it[0]]++;
        }

        for(int i=0;i<n;i++){
            if(inorder[i]==0){
                que.push(i);
            }
        }

        while(!que.empty()){
            int node = que.front();
            que.pop();
            ans.push_back(node);

            for(auto neigh : adj[node]){
                inorder[neigh]--;
                if(inorder[neigh]==0){
                    que.push(neigh);
                }
            }            
        }

        if(ans.size() == n) return ans;
        return {};
    }
};