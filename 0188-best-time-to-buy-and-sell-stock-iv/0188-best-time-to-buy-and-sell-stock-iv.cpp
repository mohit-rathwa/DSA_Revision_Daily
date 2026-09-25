class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>> (k+1 , vector<int>(2, 0)));

        for(int idx=n-1;idx>=0;idx--){
            for(int c=1;c<=k;c++){
                for(int buy = 0;buy<=1;buy++){
                    if(buy==1){
                        dp[idx][c][buy] = max(-prices[idx]+dp[idx+1][c][0],dp[idx+1][c][1]);
                    }
                    else{
                        dp[idx][c][buy] = max(+prices[idx]+dp[idx+1][c-1][1],dp[idx+1][c][0]);
                    }
                }
            }
        }
        return dp[0][k][1];
    }
};