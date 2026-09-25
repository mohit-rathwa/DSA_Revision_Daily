class Solution {
public:
    vector<vector<int>> dp;
    int solve(int idx, vector<int>&prices , int buy){
        int n = prices.size();

        if(idx >= n) return 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];

        if(buy){
            int take = -prices[idx]+solve(idx+1,prices,!buy);
            int skip = solve(idx+1,prices,buy);
            return dp[idx][buy]=max(take , skip);
        }
        else{
            int take = +prices[idx]+solve(idx+2,prices,!buy);
            int skip = solve(idx+1,prices,buy);
            return dp[idx][buy]=max(take , skip);
        }

        return 0;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n+2 , vector<int> (2 , -1));

        return solve(0 , prices , 1);
    }
};