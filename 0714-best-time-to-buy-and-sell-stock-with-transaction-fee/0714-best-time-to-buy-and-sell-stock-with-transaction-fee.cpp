class Solution {
public:
    vector<vector<int>> dp;
    int solve(int idx , vector<int>&prices , int fee,int buy){
        int n = prices.size();


        if(idx == n) return 0;
        

        if(dp[idx][buy] != -1e9) return dp[idx][buy];

        if(buy){
            int take = -prices[idx]+solve(idx+1,prices,fee,0);
            int skip = solve(idx+1,prices,fee,1);
            return dp[idx][buy]= max(take , skip);
        }
        else{
            int take = +prices[idx]-fee+solve(idx+1,prices,fee,1);
            int skip = solve(idx+1,prices,fee,0);
            return dp[idx][buy]=max(take , skip);
        }
        return 0;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        dp.assign(n+1 , vector<int> (2 , -1e9));

        return solve(0 , prices, fee, 1);
    }
};