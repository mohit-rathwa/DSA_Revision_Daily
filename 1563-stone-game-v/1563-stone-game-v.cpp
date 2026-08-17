class Solution {
public:
    vector<vector<int>> dp;
    int solve(int l ,int r,vector<int>&prefix){

        if(l>=r) return 0;
        int ans = 0;

        if(dp[l][r] != -1) return dp[l][r];

        for(int mid = l ; mid < r ; mid++){
            int l_sum = prefix[mid] - ((l>=1) ? prefix[l-1] : 0);
            int r_sum = prefix[r] - prefix[mid];

            if(l_sum < r_sum ){
                ans = max(ans , l_sum+solve(l,mid,prefix));
            }
            else if(l_sum > r_sum){
                ans = max(ans, r_sum+solve(mid+1,r,prefix));
            }
            else{
                ans = max({ans,l_sum+solve(l,mid,prefix),r_sum+solve(mid+1,r,prefix)});
            }
        }
        return  dp[l][r]=ans;
    }
    int stoneGameV(vector<int>& stone) {
        int n = stone.size();
        dp.assign(n+1 , vector<int> (n+1 , -1));
        vector<int>prefix(n,0);

        prefix[0] = stone[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+stone[i];
        }

        return solve(0 , n-1 , prefix);

    }
};