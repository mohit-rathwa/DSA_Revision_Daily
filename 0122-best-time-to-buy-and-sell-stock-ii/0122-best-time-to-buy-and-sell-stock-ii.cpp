class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1 , vector<int> ( 2, 0));

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j == 0){
                    int take = -prices[i] + dp[i+1][!j];
                    int skip = dp[i+1][j];
                    dp[i][j] = max(take , skip);
                }
                else{
                    int take = +prices[i] + dp[i+1][!j];
                    int skip = dp[i+1][j];
                    dp[i][j] = max(take , skip);
                }
            }
        }
        return dp[0][0];
    }
};