class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int  n = stones.size();
        vector<int> pre(n,0);

        pre[0] = stones[0];
        for(int i=1;i<n;i++){
            pre[i]+=(pre[i-1]+stones[i]);
        }

        int dp = pre[n-1];

        for(int i=n-2 ; i >=1 ; i--){
            
            dp = max(dp , pre[i]-dp );
        }

        return dp;

    }
};