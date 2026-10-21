class Solution {
public:
    vector<pair<int,pair<int,int>>> nodes;

    void solve(TreeNode * root , int c, int r){
        if(!root) return;

        nodes.push_back({c , {r , root->val}});

        solve(root->left , c-1 , r+1);
        solve(root->right , c+1 , r+1);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root , 0 , 0);
        vector<vector<int>> ans;

        sort(nodes.begin(),nodes.end());

        int prev_c = -1e9;

        for(auto &it : nodes){
            int val = it.second.second;
            int c = it.first;

            if(c > prev_c){
                prev_c = c;
                ans.push_back({val});
            }
            else if(c == prev_c){
                ans.back().push_back(val);
            }
        }

        return ans;
    }
};