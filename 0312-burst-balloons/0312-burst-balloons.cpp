class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i , int j , vector<int>&nums){
        int n = nums.size();

        if(i+1 == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        
        for(int k=i+1 ; k<j ;k++){
            int cost = nums[i]*nums[j]*nums[k] + solve(i , k , nums) + solve(k , j , nums);

            ans = max(cost , ans);
        }

        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n+2 , vector<int> (n+2 , -1));

        vector<int> arr(n+2,1);
        for(int i=0;i<n;i++){
            arr[i+1] = nums[i];
        }

        return solve(0 , n+1 , arr);
    }
};