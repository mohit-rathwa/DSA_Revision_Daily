class Solution {
public:
    void solve(int idx,vector<int>&candidates ,int target,vector<vector<int>>&ans,vector<int>&curr){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        if(idx<0 || target<0){
            return;
        }

        if(target>=candidates[idx]){
            curr.push_back(candidates[idx]);
            solve(idx,candidates,target-candidates[idx],ans,curr);
            curr.pop_back();
        }

        solve(idx-1, candidates , target , ans , curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> curr;

        solve(n-1 ,candidates , target , ans , curr);
        return  ans;
    }
};