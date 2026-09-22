class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> hash(n);
        int maxi = 1;
        int lst_idx = 0;
        vector<int> dp(n,1);

        for(int i=1;i<n;i++){
            hash[i] = i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i] = dp[j] + 1 ;
                    hash[i] = j;
                }
                if(maxi < dp[i]){
                    maxi = dp[i];
                    lst_idx = i;
                }
            }
        }

        vector<int> tmp;
        tmp.push_back(nums[lst_idx]);
        while(lst_idx != hash[lst_idx]){
            lst_idx= hash[lst_idx];
            tmp.push_back(nums[lst_idx]);
        }
        reverse(tmp.begin(),tmp.end());

        return tmp;
    }
};