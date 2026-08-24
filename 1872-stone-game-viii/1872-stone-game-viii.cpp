class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> dp(n , 0);

        vector<int> pre(n,0);
        pre[0] = stones[0];

        for(int i=1;i<n;i++){
            pre[i] += (pre[i-1] + stones[i]);
        }

        dp[n-1] = pre[n-1];

        for(int i=n-2 ;i>=1;i--){
            int take = pre[i] - dp[i+1];
            int skip = dp[i+1];

            dp[i] = max(take,skip);
        }
        return dp[1];

    }
};