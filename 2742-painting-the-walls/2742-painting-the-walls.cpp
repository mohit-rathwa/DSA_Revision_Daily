class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        
        for(int remain = 1 ; remain <= n ; remain++){
            dp[remain] = 1e9;
        }

        for(int idx = n-1 ; idx >= 0 ; idx--){
            vector<int> tmp(n+1,0);
            for(int remain = 0 ;remain <=n ;remain++){
                int re = max(0 , remain - (1+time[idx]));
                int take = cost[idx] + dp[re];
                int no_take = dp[remain];

                tmp[remain] = min(take , no_take);
            }
            dp=tmp; 
        }
        return dp[n];
    }
};