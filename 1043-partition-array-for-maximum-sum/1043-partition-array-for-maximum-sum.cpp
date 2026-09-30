class Solution {
public:
    vector<int> dp;
    int solve(int i , int k , vector<int>&arr ){
        int n = arr.size();

        if(i == n) return 0;
        int len = 0;
        int maxi_ans = INT_MIN;
        int curr= INT_MIN;
        if(dp[i]!= -1) return dp[i];
        for(int j=i;j<min(n,i+k);j++){
            len++;
            curr = max(curr , arr[j]);
            int ans = curr*len + solve(j+1 ,k, arr);
            maxi_ans = max(maxi_ans , ans);
        }

        return dp[i]=maxi_ans ;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        dp.assign(n , -1);

        return solve(0 , k , arr);
    }
};