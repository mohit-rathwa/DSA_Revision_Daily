class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i , int j , vector<int>&cuts){
        int n = cuts.size();

        if(i+1 == j){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for(int k=i+1;k<j;k++){
            int cost = (cuts[j]-cuts[i]) + solve(i , k , cuts) + solve(k , j, cuts);
            ans = min(ans , cost);
        }

        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        dp.assign( cuts.size() , vector<int> ( cuts.size() , -1));

        return (int)solve(0 , cuts.size()-1 , cuts);
    }
};